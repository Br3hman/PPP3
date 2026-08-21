/*
	I have copied this file from
	calculator08buggy.cpp

	[1] Starting from the file calculator08buggy.cpp, get the calculator to compile.

	-I am adding std as, I dont want to use namespace
	-I am using hearder files instead of using "std_lib_facilities.h"
	-I am also using throw std::runtime_error instead of error() function from std_lib_facilities.h
	-Added new initialization for Token Class for the kind and name
	-In delcaration() function I have added throw std::runtime_error instead of error() function from std_lib_facilities.h
		using predefined name instead of 'a' for name in declaration() function
	-In get() we need to add charator to the string not just assigning the charator to string s += ch


*/


#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
//#include <map>
#include <cmath>




struct Token {
	char kind;
	double value;
	std::string name;
	Token(): kind{0}, name{""}, value{0.0} {};  // default constructor for buffer
    Token(char ch): kind{ch}, name{""}, value{0.0} {};//initialize kind
    Token(char ch, double val): kind{ch}, name{""}, value{val} {}; //initialize kind and value
    Token(char ch, std::string n): kind{ch}, name{n}, value{0.0} {}; //initialize kind and name
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token get();
	void unget(Token t) { buffer = t; full = true; }
	Token_stream() : full(false), buffer() {}
	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	std::cin >> ch;
	switch (ch) {
	case print:   //for "print"
    case quit: // for "quite"
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
		return Token(ch);
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
	{	std::cin.unget();
	double val;
	std::cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			std::cin.unget();
			if (s == "let") return Token(let);
			return Token(name, s);
		}
		throw std::runtime_error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (std::cin >> ch)
		if (ch == c) return;
}

struct Variable {
	std::string name;
	double value;
	Variable(std::string n, double v) :name(n), value(v) { }
};

std::vector<Variable> names;

double get_value(std::string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	throw std::runtime_error("get: undefined name " + s);
}

void set_value(std::string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	throw std::runtime_error("set: undefined name " + s);
}

bool is_declared(std::string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') throw std::runtime_error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		throw std::runtime_error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
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
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') throw std::runtime_error("name expected in declaration");
	std::string name = t.name;
	if (is_declared(name)) throw std::runtime_error(name+ " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') throw std::runtime_error("= missing in declaration of "+ name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const std::string prompt = "> ";
const std::string result = "= ";

void calculate()
{
	while (true) try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		std::cout << result << statement() << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	char c;
	while (std::cin >> c && c != ';');
	return 1;
}
catch (...) {
	std::cerr << "exception\n";
	char c;
	while (std::cin >> c && c != ';');
	return 2;
}