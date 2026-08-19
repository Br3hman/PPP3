/*
[5] Write a grammar for bitwise logical expressions.
A bitwise logical expression is much like an arithmetic
expression except that the operators are

* ! (not),
* ˜ (complement),
* & (and),
* | (or), and
* ˆ (exclusive or).

Each operator does its operation to each bit of its integer operands (see PPP2.§25.5).

* prefixes: ! and ˜ are prefix unary operators.

* A ˆ binds tighter than a | (just as * binds tighter than +)

so that x|yˆz means x|(yˆz) rather than (x|y)ˆz.

The & operator binds tighter than ˆ so that xˆy&z means xˆ(y&z).
In a recursive-descent parser Highest to lowest
expression: OrExpr ;
    or_expression: XorExpr | OrExpr "|" XorExpr ;
        xor_expresion: AndExpr | XorExpr "^" AndExpr ;
            and_expresion: UnaryExpr | AndExpr "&" UnaryExpr ;
                unary_expression: "!" UnaryExpr| "~" UnaryExpr| Primary ;
                    primary_expression: Integer | Identifier | "(" Expression ")" ;


*/
#include <iostream>
#include <stdexcept>
//#include <string>
//#include <vector>
//#include <cstddef>   // for std::size_t
//#include <algorithm>
//#include <map>
//#include<cmath>
class Token {
    public:
        char kind; //what kind of a Token
        double value; //for numbers: a value
    Token(char ch): kind{ch}, value{0.0} {};
    Token(char ch, double val): kind{ch}, value{val} {};
    Token(): kind{0}, value{0.0} {};  // default constructor for buffer
};

//================================================================
class Token_stream{
    public:
        Token get(); // get a token
        void putback(Token t); // put a Token back
    private:
        bool full = false; // is there a Token in the buffer?
        Token buffer; // putback() saves its token here

};
//------------------------------------------------
void Token_stream::putback(Token t){
    if(full)
        throw std::runtime_error("Token stream buffer is full");
    buffer = t; // copy t to the buffer
    full = true; // buffer is now full
}
//------------------------------------------------
Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }
    char ch = '\0';
    if(!(std::cin>>ch))
        throw std::runtime_error("No input");
    switch (ch)
    {
        case ';':   //for "print"
        case 'q': // for "quite"
        case 'x': // for "exit"
        case '=': // for "print"
        case '(': case ')':
        case '!': case '~':  case '&': case '^': case '|':
            return Token{ch};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6':
        case '7': case '8': case '9': // we are using {} block because we need to create locak variable 
         {
            std::cin.putback(ch); // put digit back into the input stream
            double val = 0.0;
            std::cin>>val;
            return Token('8',val); // let '8' represent a number and using other constructor of Token class here
         }
        default:
            throw std::runtime_error("Bad Token");
    }

}

//------------------------------------------------
Token_stream ts;                               // provides get() and putback()

//--------------Forward declarations----------------------------------
int or_expression();
int xor_expression();
int and_expression();
int unary_expression();
int primary_expression();

int primary_expression(){
    Token t = ts.get();
    switch (t.kind)
    {
    case '8': // we use '8' to represent a number
        return t.value;
    case '(':
    {
        int d = or_expression();
        t = ts.get();
        if (t.kind != ')') throw std::runtime_error("')' expected");
        return d;
    }
    default:
        throw std::runtime_error("primary expected");
    }
}
int unary_expression(){
    Token t = ts.get();
    switch (t.kind)
    {
    case '!':
        return !unary_expression();
    case '~':
        return ~unary_expression();
    default:
        ts.putback(t);
        return primary_expression();
    }
}

int and_expression(){
    int left = unary_expression();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '&':
            left &=  unary_expression();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int xor_expression(){
    int left = and_expression();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '^':
            left ^= and_expression();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
int or_expression(){
    int left = xor_expression();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '|': // finding the | or highest
            left |= xor_expression();
            t = ts.get(); //get next token if any
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main() {
    try
    {
        int val = 0;
        std::cout << "\tWelcome to our simple bitwise logical calculator.\n"
        "Please enter expressions using Operators: & | ^ ! ~ ( )\n"
		"Solve using ';' or '=' Exit with 'q' or 'x'\n";
        while (std::cin)
        {
          Token t = ts.get();
          if(t.kind == 'q') break;
           if (t.kind == ';' ){ // ';' for print
                std::cout << "=" << val << '\n';
            }
            else if(t.kind == '='){ // ';' for print
                std::cout << val << '\n';

            }
            else{
                ts.putback(t);
                val = or_expression();
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


