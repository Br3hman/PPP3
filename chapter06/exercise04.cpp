/*
	[4] The get_value(), set_value(), is_declared(), and define_name()
	functions all operate on the variable var_table. Define a class called
	Symbol_table with a member var_table of type vector<Variable> and member
	functions get(), set(), is_declared(), and declare(). Rewrite the calculator
	to use a variable of type Symbol_table.

	Grammar for input:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Statement:
		Declaration
		Assignment
		Expression
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary
	Primary:
		Number
		Name
		"(" Expression ")"
		"-" Primary
		"+" Primary
		"sqrt" "(" Expression ")"
		"pow" "(" Expression "," Expression ")"
	Number:
		floating-point-number
	Name:
		alphanumeric sequence of characters, may include '_'
	Print:
		";"
	Quit:
		"quit"
		"Q"
	Declaration:
		"#" Name "=" Expression
	Assignment:
		Name "=" Expression
*/


#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
//#include <map>
#include <cmath>
#include <climits>


//-------------- Symbolic constants -----------
const char let = 'L';
const std::string quit = "quit";
const char print = ';';
const char number = '8';
const char name = 'a';
const char declkey = '#'; //declaration keyword
constexpr char squareroot = 's';
constexpr char power = 'p';
constexpr char assignment_operator = '='; //assignment operator
constexpr char constant = 'c'; //constant variable
const std::string constant_declaration = "const"; //constant declaration keyword


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


Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // do we already have a Token ready? then remove from buffer
	char ch;
	std::cin >> ch; // note that >> skips the whitespace (space, newline, tab, etc)
	if (!std::cin) return Token('Q'); // stream failed/EOF: treat as quit instead of looping forever
	switch (ch) {
	// single-character tokens are returned as-is
	case print:   //for "print"
	case 'Q': // for a bare 'Q' character
	case '(':
	case ')':
	case ',': // separates the two arguments of pow(...)
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
	case declkey:
		return Token(let);//"let" is the only recognized keyword here
	default:
		if (isalpha(ch) || ch == '#') {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '#' || ch == '_')) s += ch; // '_' lets names contain underscores; '#' can't actually occur here since it's already caught by case declkey above
			std::cin.unget(); // last char read wasn't part of the word, so put it back
			if(s=="quit") return Token('Q');
			if (s == "sqrt") return Token(squareroot);
			if (s == "pow") return Token(power);
			if (s == constant_declaration){
				std::cout<<"arrived in constant_declaration\n";
				return Token(constant); // constant declaration keyword
			}
			return Token(name, s); // anything else (including the word "quit") is a variable name
		}
		throw std::runtime_error("get(): Bad token");
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

class Variable{ // a declared name and the value currently bound to it
    public:
        std::string name;
        double value;
		bool is_constant; // true if the variable is a constant
        Variable(std::string n, double v, bool c = false): name{n}, value{v}, is_constant{c} {};
};

class Symbol_table{
	public:
		std::vector<Variable> var_table; // table of all declared variables
		double get(std::string s); // return the value of the Variable named s
		void set(std::string s, double d); // set Variable named s to value d
		bool is_declared(std::string var); // check if a variable is already declared
		double define_name(std::string var, double val, bool is_constant = false); // declare a variable directly, bypassing the parser (used for predefined names like pi/e/k)
};


//std::vector<Variable> var_table; // table of all declared variables

double Symbol_table::get(std::string s)
// return the value of the Variable named s
{
    for(const Variable& v:var_table){
        if(v.name == s)
            return v.value;
    }
    throw std::runtime_error("trying to read undefined variable");
}

void Symbol_table::set(std::string s, double d)
// set Variable named s to value d
{
    for(Variable& v: var_table){
        if(v.name == s){
            if(v.is_constant) throw std::runtime_error("cannot assign to a constant variable");
            v.value = d;
            return;
        }
    }
    throw std::runtime_error("trying to write undefined variable");
}

bool Symbol_table::is_declared(std::string var){
    for(const Variable& v:var_table){
        if(v.name == var)
            return true;
    }
    return false;
}

Token_stream ts; // the single, global token stream read from std::cin
Symbol_table st; // the single, global symbol table

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
		return st.get(t.name);
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
	case power:
		{
			t = ts.get();
			if (t.kind != '(') throw std::runtime_error("'(' expected");
			double d = expression();
			t = ts.get();
			if (t.kind != ',') throw std::runtime_error("',' expected");
			int i = static_cast<int>(expression());
			t = ts.get();
			if (t.kind != ')') throw std::runtime_error("')' expected");
			return std::pow(d,i);
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
		case '%': // For double we have fmode() from std that do as x%y = x-y*int(x/y);
        {
            double d = primary();
            if(std::abs(d) > 0 ){
                left = std::fmod(left,d);
            }else{
                throw std::runtime_error("%:divide by zero");
            }
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

// Declaration: ("#" | "const") Name "=" Expression
double declaration(bool is_constant = false)
{
	Token t = ts.get();
	if (t.kind != name) throw std::runtime_error("name expected in declaration");
	std::string n = t.name;
	if (st.is_declared(n)) throw std::runtime_error(n+ " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') throw std::runtime_error("= missing in declaration of "+ n);
	double d = expression();
	st.var_table.push_back(Variable(n, d, is_constant));
	return d;
}

double assignment(std::string name )
{
	if (!st.is_declared(name)) throw std::runtime_error(name+ " is not declared");
	double d = expression();
	st.set(name, d);
	return d;
}

double define_name(std::string var, double val, bool is_constant = false)
// declare a variable directly, bypassing the parser (used for predefined names like pi/e/k)
//extended to allow for constant variables
{
    if(st.is_declared(var)){
        throw std::runtime_error(var + " declared twice");
    }
    st.var_table.push_back(Variable{var, val, is_constant});
    return val;
}


// Statement: Declaration | Expression
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case constant:
		return declaration(true); // same rule as "let", just marked constant
	case name:
    {
        char ch = std::cin.get();
        while (ch  == ' ' || ch == '\n') // skip whitespace and newline characters to detect assignment
            ch = std::cin.get();
        if(ch == assignment_operator){
            return assignment(t.name); // direct assignment (example var2 = 2)
        }
        // if not an assignment — put characters back and treat as expression
        ts.unget(t); // put name token in the buffer
        std::cin.putback(ch);
        return expression();
    }
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
		if (t.kind == 'Q') return; // bare 'Q' character ends the program
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
	//predefined names, added a boolean flag to indicate that they are constants
    define_name("pi",3.1415926535,true);
    define_name("e",2.7182818284,true);
	define_name("k",1000,true);

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