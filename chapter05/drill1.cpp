/*

[1] Take the calculator from the file calculator02buggy.cpp. 
Get it to compile. You need to find and fix a few bugs. 
Those bugs are not in the text in the book. Find the three 
logic errors deviously inserted in calculator02buggy.cpp and 
remove them so that the calculator produces correct results.

//class Token 
//class Token_stream 

//void Token_stream::putback(Token t) 
//Token Token_stream::get() 

//Token_stream ts;                               // provides get() and putback()
//double expression();                         // declaration so that primary() can call expression()

//double primary()                 // deal with numbers and parentheses
//double term()                      // deal with * and /
// double expression()          // deal with + and -


*/
#include <iostream>
#include<PPP_error.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
#include<cmath>

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
        PPP::error("no input");
    
    switch (ch)
    {
    case ';':   //for "print"
    case 'q': // for "quite"
    case '(': case ')': case '+': case '-': case '*': case '/': 
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
        PPP::error("Bad Token");
    }
}

//------------------------------------------------
Token_stream ts;                               // provides get() and putback()

//-----------Forward declaration of expression() function----------------
double expression();                         // declaration so that primary() can call expression()

//-----------------primary() function--------------------------
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') PPP::error("')' expected");
        return d;

    }
    case '8': // we use '8' to represent a number
        return t.value;
    default:
        PPP::error("primary expected");
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
                PPP::error("Division by zero");
            }
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

int main() {
    try{
        double val = 0.0;
        std::cout << "\tWelcome to our simple calculator. \nPlease enter expressions using floating-point numbers.\n";
        while (std::cin)
        {
            
            Token t = ts.get();
            if (t.kind == 'q') break; // 'q' for quit
            if (t.kind == ';'){ // ';' for print
                std::cout << "=" << val << '\n';
            }
            else{
                ts.putback(t);
            }
                
            val = expression();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Exit with error
    }


    return 0;
}

   

    
