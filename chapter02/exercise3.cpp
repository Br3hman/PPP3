/*
Write a program that doesn’t do anything, 
but declares a number of variables with legal 
and illegal names (such as int double = 0;), 
so that you can see how the compiler reacts.
*/
int main() {
    int double = 0; // illegal name
    int my_variable = 1; // legal name
    int 2ndVariable = 2; // illegal name
    int variableName = 3; // legal name
    int _underscore = 4; // legal name
    int variable-name = 5; // illegal name
    int variableName123 = 6; // legal name
    int variableName! = 7; // illegal name

    return 0;
}