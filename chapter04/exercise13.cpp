/*
[13] The program is a bit tedious because the answer is hard-coded into the program. 
Make a version where the user can play repeatedly (without stopping and restarting the program) 
and each game has a new set of four digits. You can get four random digits by calling the 
random number generator random_int(0,9) from PPP_support (and §4.7.5) four times. 
You will note that if you run that program repeatedly, it will pick the same sequence 
of four digits each time you start the program. To avoid that, ask the user to enter a 
number (any number) and call seed(n), also from PPP_support, where n is the number the 
user entered before calling random_int(0,10). Such an n is called a seed, and different 
seeds give different sequences of random numbers.
*/
#include <iostream>
//#include <string>
#include <vector>
#include <algorithm>
//#include <cstdint>
//#include <cmath>
#include <limits>
#include <PPP_random.h>

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

std::vector<int> get_init(){
    PPP::seed(PPP::random_int(0, 10));
    std::vector<int> v;
    for (int i = 0; i < 4; ++i)
        v.push_back(PPP::random_int(0, 9));
    return v;
}

int main(){
    std::vector<int> integers=get_init();
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
        //std::cout<<"you have entered:"<<guess.size()<<" numbers, please enter the next number: ";


        if(guess.size() >= 4){
            if(guess[0]==integers[0] && guess[1]==integers[1] && guess[2]==integers[2] && guess[3]==integers[3]){
                std::cout<<"Congratulations! You guessed the correct number!"<<std::endl;
                std::cout<<"The correct number was: ";
                for(const int& num:integers){
                    std::cout<<num;
                }
                std::cout<<std::endl;
                integers.clear();
                integers=get_init();
                
            }else{
                auto [number_match,position_match] = check_guess(guess,integers);
                    std::cout<<"You have "<<position_match<<" Bulls and "<<number_match<<" cow(s)."<<std::endl;


            }
            guess.clear();
            continue;
        }
    }


    return 0; // Exit without error
}

    
