/*
[2] Add the ability to use {} as well as () in the program, so that {(4+5)*6} / (3+4) will be a valid expression.
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
//#include <map>
#include<cmath>
//-------------- Symbolic constants -----------
// Starting from chapter 6, we clean up he code
constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
const std::string prompt = ">";
const std::string result = "=";

const char name = 'a'; // name token
const char let = 'L';   //declaration token
const std::string declkey = "let"; //declaration keyword
class Token {
    public:
        char kind; //what kind of a Token
        double value; //for numbers: a value
        std::string name;
    Token(): kind{0}, name{""}, value{0.0} {};  // default constructor for buffer
    Token(char ch): kind{ch}, name{""}, value{0.0} {};//initialize kind
    Token(char ch, double val): kind{ch}, name{""}, value{val} {}; //initialize kind and value
    Token(char ch, std::string n): kind{ch}, name{n}, value{0.0} {}; //initialize kind and name

};
class Variable{
    public:
        std::string name;
        double value;
        Variable(std::string n, double v): name{n}, value{v} {};
};
//================================================================
class Token_stream{
    public:
        Token get(); // get a token
        void putback(Token t); // put a Token back
        void ignore(char c); // discard characters up to and including a c
    private:
        bool full = false; // is there a Token in the buffer?
        Token buffer; // putback() saves its token here

};

//------------------------------------------------
void Token_stream::ignore(char c){
    //c represents the kind of Token we want to ignore
    if(full && c == buffer.kind){// first look in buffer:
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while(std::cin >> ch)
        if(ch == c) return;
}
void Token_stream::putback(Token t){
    buffer = t; // copy t to the buffer
    full = true; // buffer is now full
}
//------------------------------------------------
Token Token_stream::get(){
    if(full){
        full = false; // do we already have a Token ready?
        return buffer; // remove from buffer
    }

    char ch =0;
    if (!(std::cin >> ch))     // note that >> skips the whitespace (space, newline, tab, etc)
        throw std::runtime_error("no input");

    switch (ch)
    {
    case print:   //for "print"
    case quit: // for "quite"
    case '{':
    case '}':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ch}; // let each charater represent it self, here is Token constructor used
        //break; // we already return it will reached
    case '.':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6':
    case '7': case '8': case '9': // we are using {} block because we need to create locak variable
     {
        std::cin.putback(ch); // put digit back into the input stream
        double val = 0.0;
        std::cin>>val;
        return Token('8',val); // let '8' represent a number and using other constructor of Token class here
     }
    default:
        if (isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
			std::cin.putback(ch);
			if (s == declkey) return Token(let);
			return Token(name, s);
		}
        throw std::runtime_error("Bad Token");
        return Token{}; // unreachable; silences -Wreturn-type
    }
}

//------------------------------------------------
Token_stream ts;                               // provides get() and putback()
//--------------------------------------------------
std::vector<Variable> var_table;

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
double define_name(std::string var, double val){
    if(is_declared(var)){
        throw std::runtime_error(var + " declared twice");
    }
    var_table.push_back(Variable{var, val});
    return val;
}

//--------------------------------------------------
void clean_up_mess(){
    ts.ignore(print);
}

//-----------Forward declaration for functions----------------
double statement();
double expression();                         // declaration so that primary() can call expression()

//-----------------primary() function--------------------------
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}')
        {
            std::cout<< "got "<< t.kind<<"\n";{}
            throw std::runtime_error("'}' expected");
        }
        return d;
    }
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw std::runtime_error("')' expected");
        return d;

    }
    case number: // we use '8' to represent a number
        return t.value;
    case '-':
        return -primary();
    case '+':
        return primary();
    case name:
		return get_value(t.name);
    default:
        throw std::runtime_error("primary expected");
        return 0; // unreachable; silences -Wreturn-type
    }
}

//----------------term() function-------------------------------

double term(){
    double left = primary();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '*': // we multiply left with next primary()
            left *= primary();
            t = ts.get();  //get next
            break;
        case '/': { // we divide left with next primary()
            double d = primary();
            if(std::abs(d)>0){
                left /=d;
                t=ts.get();
                break;
            }
            else{
                throw std::runtime_error("Division by zero");
            }
        }
        case '%': // For double we have fmode() from std that do as x%y = x-y*int(x/y);
        {
            double d = primary();
            if(std::abs(d) > 0 ){
                left = std::fmod(left,d);
            }else{
                throw std::runtime_error("%:divide by zero");
            }
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); //put t back to the Token stream
            return left;
        }
    }
}

double expression(){
    double left = term();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '+': // 1+(2*3) where 2*3 are handled with Term and + expression with left is here
            left += term();
            t = ts.get(); //get next token if any
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }

}
double declaration(){
    // assume we have seen "let"
    // handle: name = expression
    // declare a varaible called "name" with initial value "expersion()"
    Token t = ts.get();
    if(t.kind != name)
        throw std::runtime_error("name expected in declaration ");
    
    Token t2 = ts.get();
    if (t2.kind != '=')
    {
        throw std::runtime_error("= missing in declaration of "+t.name);
    }
    double d = expression();
    define_name(t.name,d);
    return d;
}

double statement(){
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.putback(t);
       return expression();
    }
}


void calculate()
{
 while (std::cin)
        try{
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print)                  // first discard all "prints"
                     t=ts.get();
            if (t.kind == quit)                          // quit
                     return;
            ts.putback(t);
            std::cout << result << statement() << '\n';
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';              // write error message
            clean_up_mess();
  }
}

/*
Ideally, a function performs a single logical action.
Having main() perform both of these actions obscures
the structure of the program.
*/

int main() {
    try{
        //predefined names
        define_name("pi",3.1415926535);
        define_name("e",2.7182818284);

        calculate();
         return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
return 1; // Exit with error
    }
    catch (...) {
        std::cerr << "Unknown exception!" << std::endl;
        return 2; // Exit with error
    }
}

