/*

*/
#include <iostream>
#include<PPP_error.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
#include<cmath>
#include<vector>

class Token {
    public:
        char kind; //what kind of a Token
        double value; //for numbers: a value
    Token(char ch): kind{ch}, value{0.0} {};
    Token(char ch, double val): kind{ch}, value{val} {};
    Token(): kind{0}, value{0.0} {};  // default constructor for buffer
};

struct TraceNode {
    const char* name;
    std::vector<TraceNode> children;
};

std::vector<TraceNode> g_trace_roots;
std::vector<TraceNode*> g_trace_stack;

class TraceScope {
public:
    explicit TraceScope(const char* fn_name) {
        if (g_trace_stack.empty()) {
            g_trace_roots.push_back(TraceNode{fn_name, {}});
            g_trace_stack.push_back(&g_trace_roots.back());
        } else {
            TraceNode* parent = g_trace_stack.back();
            parent->children.push_back(TraceNode{fn_name, {}});
            g_trace_stack.push_back(&parent->children.back());
        }
    }

    ~TraceScope() {
        if (!g_trace_stack.empty()) {
            g_trace_stack.pop_back();
        }
    }
};

void print_trace_tree_node(const TraceNode& node, const std::string& prefix, bool is_last) {
    std::cout << prefix;
    std::cout << (is_last ? "`-- " : "|-- ");
    std::cout << node.name << '\n';

    std::string child_prefix = prefix + (is_last ? "    " : "|   ");
    for (std::size_t i = 0; i < node.children.size(); ++i) {
        bool child_is_last = (i + 1 == node.children.size());
        print_trace_tree_node(node.children[i], child_prefix, child_is_last);
    }
}

void print_last_call_tree() {
    if (g_trace_roots.empty()) {
        std::cout << "\nNo calls traced yet.\n";
        return;
    }

    const TraceNode& root = g_trace_roots.back();
    std::cout << "\nLast call tree:\n";
    std::cout << root.name << '\n';
    for (std::size_t i = 0; i < root.children.size(); ++i) {
        bool is_last = (i + 1 == root.children.size());
        print_trace_tree_node(root.children[i], "", is_last);
    }
}

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
    TraceScope trace{"Token_stream::putback"};
    buffer = t; // copy t to the buffer
    full = true; // buffer is now full
}
//------------------------------------------------
Token Token_stream::get(){
    TraceScope trace{"Token_stream::get"};
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
    TraceScope trace{"primary"};
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

//----------------term() function-------------------------------

double term(){
    TraceScope trace{"term"};
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
    TraceScope trace{"expression"};
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
        TraceScope trace{"main"};
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

    print_last_call_tree();
    return 0;
}
