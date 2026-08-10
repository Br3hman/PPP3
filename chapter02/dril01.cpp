/*
Write a program that produces a simple form letter based on user input. 
Begin by typing the code from §2.1 prompting a user to enter his or her 
first name and writing “Hello, first_name” where first_name is the name 
entered by the user. Then modify your code as follows: change the prompt to 
“Enter the name of the person you want to write to” and change the output to 
“Dear first_name,”. Don’t forget the comma.
1. Enter your first name: John
2. Enter the name of the person you want to write to: Mary
3. Dear Mary,
*/

#include <iostream>
#include <string>
int main(){
    std::string first_name;
    std::string recipient_name;

    std::cout << "Enter your first name: ";
    std::cin >> first_name;

    std::cout << "Enter the name of person you want to write to: ";
    std::cin >> recipient_name;

    std::cout << "Dear " << recipient_name << "," << std::endl;
    return 0;
}