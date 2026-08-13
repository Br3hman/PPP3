/*
[12] Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” 
The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) 
and it is the user’s task to discover those numbers by repeated guesses. Say the number 
to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1 cow” 
because the user got one digit (1) right and in the right position (a bull) and one digit 
(3) right but in the wrong position (a cow). The guessing continues until the user gets 
four bulls, that is, has the four digits correct and in the correct order.
*/
#include <iostream>
//#include <string>
#include <vector>
#include <algorithm>
//#include <cstdint>
//#include <cmath>
#include <limits>

std::pair<int, int> check_guess(const std::vector<int>& guess, const std::vector<int>& integers){
    int correct_position{0};
    int correct_number{0};
    for(size_t i = 0; i < guess.size(); ++i){
        if(guess[i]==integers[i]){
            ++correct_position;
        }else{
            // need to check if the number exists in the integers vector
            auto it = std::find(integers.begin(), integers.end(), guess[i]); 
            if(it != integers.end()){
                ++correct_number;
            }
        }
     
    }
    return {correct_number, correct_position};
}

int main(){
    std::vector<int> integers{1,2,3,4};
    std::vector<int> guess;
    std::cout<<"Please guess a number of four digits in the range [0, 9] (inclusive): ";
    int number{0};
    while (std::cin>>number)
    {
        if(number < 0 || number > 9){
            std::cerr<<"Error: Please enter a number in the range [0, 9] (inclusive)."<<std::endl;
            continue;
        }
        guess.push_back(number);
        std::cout<<"you have entered:"<<guess.size()<<" numbers, please enter the next number: ";


        if(guess.size() >= 4){
            if(guess[0]==integers[0] && guess[1]==integers[1] && guess[2]==integers[2] && guess[3]==integers[3]){
                std::cout<<"Congratulations! You guessed the correct number!"<<std::endl;
                break;
            }else{
                auto [number_match,position_match] = check_guess(guess,integers);
                    std::cout<<"You have "<<position_match<<" Bulls and "<<number_match<<" cow(s)."<<std::endl;
            }
            guess.clear();
            break;
        }
    }


    return 0; // Exit without error
}

    
