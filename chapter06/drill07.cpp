/*
[7] Give the user a square root function sqrt(),
for example, sqrt(2+6.7). Naturally, the value of sqrt(x)
is the square root of x; for example, sqrt(9) is 3.
Use the standard-library sqrt() function to implement that calculator sqrt().
Remember to update the comments, including the grammar.
	Grammar for input:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Statement:
		Declaration
		Expression
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
	Primary:
		Number
		Name
		"(" Expression ")"
		"-" Primary
		"+" Primary
		"sqrt" "(" Expression ")"
	Number:
		floating-point-number
	Name:
		alphanumeric sequence of characters
	Print:
		";"
	Quit:
		"quit"
	Declaration:
		"let" Name "=" Expression
*/


#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
//#include <map>
#include <cmath>




struct Token {
	char kind; //what kind of a Token
	double value; //for number: value
	std::string name; //Name of the token
	Token(): kind{0}, name{""}, value{0.0} {};  // default constructor for buffer
    Token(char ch): kind{ch}, name{""}, value{0.0} {};//initialize kind
    Token(char ch, double val): kind{ch}, name{""}, value{val} {}; //initialize kind and value
    Token(char ch, std::string n): kind{ch}, name{n}, value{0.0} {}; //initialize kind and name
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token get(); // get a token
	void unget(Token t) { buffer = t; full = true; } // put a Token back
	Token_stream() : full(false), buffer() {} //initialize the object
	void ignore(char); // discard characters up to and including a c
};

//-------------- Symbolic constants -----------
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const std::string declkey = "let"; //declaration keyword
constexpr char squareroot = 's';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // do we already have a Token ready? then remove from buffer
	char ch;
	std::cin >> ch; // note that >> skips the whitespace (space, newline, tab, etc)
	switch (ch) {
	// single-character tokens are returned as-is
	case print:   //for "print"
	case quit: // for a bare 'Q' character
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
		return Token(ch);
	// start of a floating-point number
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	std::cin.unget(); // put the digit back so >> can read the whole number
	double val;
	std::cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // collect the rest of the word
			std::cin.unget(); // last char read wasn't part of the word, so put it back
			if (s == declkey) return Token(let); // "let" is the only recognized keyword here
			if (s == "sqrt") return Token(squareroot);
			return Token(name, s); // anything else (including the word "quit") is a variable name
		}
		throw std::runtime_error("Bad token");
	}
}

void Token_stream::ignore(char c)
	//c represents the kind of Token we want to ignore
{
	if (full && c == buffer.kind) {// first look in buffer
		full = false;
		return;
	}
	full = false;
	// now search input:
	char ch;
	while (std::cin >> ch)
		if (ch == c) return;
}

class Variable{
    public:
        std::string name;
        double value;
        Variable(std::string n, double v): name{n}, value{v} {};
};

std::vector<Variable> var_table; // table of all declared variables

double get_value(std::string s)
// return the value of the Variable named s
{
    for(const Variable& v:var_table){
        if(v.name == s)
            return v.value;
    }
    throw std::runtime_error("trying to read undefined variable");
}

void set_value(std::string s, double d)
// set Variable named s to value d
{
    for(Variable& v: var_table){
        if(v.name == s){
            v.value = d;
            return;
        }
    }
    throw std::runtime_error("trying to write undefined variable");
}

bool is_declared(std::string var){
    for(const Variable& v:var_table){
        if(v.name == var)
            return true;
    }
    return false;
}

Token_stream ts; // the single, global token stream read from std::cin

double expression(); // forward declaration: expression() and term() call each other

// Primary: Number | Name | "(" Expression ")" | "-" Primary | sqrt "(" Expression ")"
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') throw std::runtime_error("'(' expected");
	} // falls through to return d after the closing ')' check
	case '-':
		return -primary();
	 case '+':
        return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case squareroot:
	{
		t = ts.get();
		if (t.kind != '(') throw std::runtime_error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ')') throw std::runtime_error("')' expected");
		if( d < 0) throw std::runtime_error("Negative number sqrt is not allowed");
		return std::sqrt(d);
	}
	default:
		throw std::runtime_error("primary expected");
	}
}

// Term: Primary | Term "*" Primary | Term "/" Primary
double term()
{
	double left = primary();
	while (true) { // keep consuming * and / left-to-right
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) throw std::runtime_error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t); // not part of this term, give it back
			return left;
		}
	}
}

// Expression: Term | Expression "+" Term | Expression "-" Term
double expression()
{
	double left = term();
	while (true) { // keep consuming + and - left-to-right
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t); // not part of this expression, give it back
			return left;
		}
	}
}

// Declaration: "let" Name "=" Expression
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') throw std::runtime_error("name expected in declaration");
	std::string name = t.name;
	if (is_declared(name)) throw std::runtime_error(name+ " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') throw std::runtime_error("= missing in declaration of "+ name);
	double d = expression();
	var_table.push_back(Variable(name, d));
	return d;
}

double define_name(std::string var, double val){
    if(is_declared(var)){
        throw std::runtime_error(var + " declared twice");
    }
    var_table.push_back(Variable{var, val});
    return val;
}


// Statement: Declaration | Expression
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t); // not "let", so put the token back for expression() to read
		return expression();
	}
}

void clean_up_mess() // recover after an error by discarding the rest of the bad statement
{
	ts.ignore(print);
}

const std::string prompt = "> ";
const std::string result = "= ";

// main read-eval-print loop
void calculate()
{
	while (true) try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // skip empty statements (repeated ';')
		if (t.kind == quit) return; // bare 'Q' character ends the program
		ts.unget(t);
		std::cout << result << statement() << std::endl;
	}
	catch (std::runtime_error& e) { // report the error and keep going
		std::cerr << e.what() << std::endl;
		clean_up_mess();
	}
}

int main()

try {
	//predefined names
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);
	define_name("k",1000);

	calculate();
	return 0;
}
catch (std::exception& e) { // last-resort handler for errors calculate() doesn't catch
	std::cerr << "exception: " << e.what() << std::endl;
	char c;
	while (std::cin >> c && c != ';'); // drain input up to the next statement separator
	return 1;
}
catch (...) { // catch anything not derived from std::exception
	std::cerr << "exception\n";
	char c;
	while (std::cin >> c && c != ';');
	return 2;
}