/*
[3] Add a factorial operator: use a suffix ! operator to represent “factorial.” For example,
the expression 7! means 7 * 6 * 5 * 4 * 3 * 2 * 1. Make ! bind tighter than * and /; that is,
7*8! means 7*(8!) rather than (7*8)!. Begin by modifying the grammar to account for a
higher-level operator. To agree with the standard mathematical definition of factorial,
let 0! evaluate to 1. Hint: The calculator functions deal with doubles, but factorial
is defined only for ints, so just for x!, assign the x to an int and calculate the
factorial of that int.

1. Create a function that takes an int and returns the factorial of that int. If the int is
    negative, call error() to report that factorial is not defined for negative numbers.
    If the int is 0 or 1, return 1. Otherwise, use a loop to calculate the factorial.
2. Create a function that takes a double and returns the factorial of that double. Assign
    the double to an int and call the function from step 1.
3. Create a function that modifies use of primary() in term() as postfix_primary() to
handle the ! operator. Call postfix_primary() from term() instead of primary().


*/
#include <iostream>
#include<PPP_error.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
#include<cmath>


double getfactorial(int n){
    if(n<0){
        PPP::error("Factorial is not defined for negative numbers");
    }
    if(n==0 || n==1){
        return 1;
    }
    double result = 1;
    for(int i=2; i<=n; ++i){
        result *= i;
    }
    return result;
}

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
    case 'x': // for "exit"
    case '=': // for "print"
    case '{':case '}':
    case '(': case ')': case '+': case '-': case '!': case '*': case '/':
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
        return Token{}; // unreachable; silences -Wreturn-type
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
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}')
        {
            std::cout<< "got "<< t.kind<<"\n";{}
            PPP::error("'}' expected");
        }
        return d;
    }
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
        return 0; // unreachable; silences -Wreturn-type
    }
}
//----------------getPostfix() function--------------------------
double postfix_primary(){
    double left = primary(); // reads a number or parenthesized experssion
    Token t = ts.get(); //read the next token
    while (t.kind == '!') // now I need to take factorial
    {
        left = getfactorial(left);
        t = ts.get();
    }
    ts.putback(t);
    return left;
}
//----------------term() function-------------------------------

double term(){
    double left = postfix_primary();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '*': // we multiply left with next primary()
            left *= postfix_primary();
            t = ts.get();  //get next
            break;
        case '/': { // we divide left with next primary()
            double d = postfix_primary();
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
            if (t.kind == 'q' || t.kind == 'x'){
                break; // 'q' for quit
            }
            if (t.kind == ';' ){ // ';' for print
                std::cout << "=" << val << '\n';
            }
            else if(t.kind == '='){ // ';' for print
                std::cout << val << '\n';

            }
            else{
                ts.putback(t);
                val = expression();
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Exit with error
    }


    return 0;
}


