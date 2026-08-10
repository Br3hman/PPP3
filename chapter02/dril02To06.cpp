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
4. Add an introductory line or two, like “How are you? I am fine. I miss you.” 
Be sure to indent the first line. 
5. Add a few more lines of your choosing – it’s your letter. 
6. Now prompt the user for the name of another friend and store it in friend_name. 
Add a line to your letter: “Have you seen friend_name lately?” 
7. Prompt the user to enter the age of the recipient and assign it to an int variable age. 
8. Have your program write “I hear you just had a birthday and you are age years old.” 
If age is 0 or less or 110 or more, call simple_error("you’re kidding!") using simple_error() from PPP_support. 
9. Add this to your letter: 
    If your friend is under 12, write “Next year you will be age+1.” 
    If your friend is 17, write “Next year you will be able to vote.” 
    If your friend is over 70, write “Are you retired?” 
    Check your program to make sure it responds appropriately to each kind of value. 
10. Add “Yours sincerely,” followed by two blank lines for a signature, followed by your name.
*/

#include <iostream>
#include "PPP_error.h"

int main(){
    std::string first_name;
    std::string recipient_name;
    std::string friend_name;
    int recipient_age{0};


    std::cout << "Enter your first name: ";
    std::cin >> first_name;

    std::cout << "Enter the name of person you want to write to and their age: ";
    std::cin >> recipient_name >> recipient_age;
 
    std::cout << "Enter the name of another friend: ";
    std::cin >> friend_name;

    std::cout << "Dear " << recipient_name << "," << std::endl;
    std::cout << "\tHow are you? I am fine. I miss you." << std::endl;
    std::cout << "\tI hope you are doing well." << std::endl;

    if(recipient_age <= 0 || recipient_age >= 110){
        PPP::simple_error("you're kidding!");
    }
    else {
        std::cout << "\tI hear you just had a birthday and you are " << recipient_age << " years old." << std::endl;
        if(recipient_age < 12){
            std::cout << "\tNext year you will be " << recipient_age + 1 << "." << std::endl;
        }
        else if(recipient_age == 17){
            std::cout << "\tNext year you will be able to vote." << std::endl;
        }
        else if(recipient_age > 70){
            std::cout << "\tAre you retired?" << std::endl;
        }
    }
    

    std::cout << "\tHave you seen " << friend_name << " lately?" << std::endl;

    std::cout << "Yours sincerely," << std::endl;
    std::cout << std::endl <<first_name << std::endl;

    return 0;
}