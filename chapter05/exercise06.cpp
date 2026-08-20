/*
[6] Redo the “Bulls and Cows” game from exercise 12 in Chapter 4 to
use four letters rather than four digits.



*/
#include <iostream>
#include <stdexcept>
//#include <string>
#include <vector>
//#include <cstddef>   // for std::size_t
#include <algorithm>
//#include <map>
//#include<cmath>

class BullsCows{
    private:
        std::vector<char> letters;
    public:
        BullsCows(std::vector<char> ch): letters{ch} {};
        BullsCows(): letters{'w','o','r','d'} {};
        std::pair<int, int> check_guess(const std::vector<char>& guess);
        char getLetter(int index);
};

char BullsCows::getLetter(int index){
    if (index > letters.size())
    {
        throw std::runtime_error("index is out of range");
    }
    return letters[index];
}

std::pair<int,int> BullsCows::check_guess(const std::vector<char>& guess){
        int correct_position{0};
    int correct_number{0};
    for(size_t i = 0; i < guess.size(); ++i){
        if(guess[i]==letters[i]){
            ++correct_position;
        }else{
            // need to check if the number exists in the integers vector
            auto it = std::find(letters.begin(), letters.end(), guess[i]);
            if(it != letters.end()){
                ++correct_number;
            }
        }
    }
    return {correct_number, correct_position};
}


int main() {
    try
    {
        BullsCows word;
        std::vector<char> guess;
        std::cout<< "Please guess a word of four letters: ";
        char ch;
        while (std::cin >> ch)
        {
            if(!(std::isalpha(static_cast<unsigned char>(ch)))){
                std::cout<<"Please enter only vaild letters (a to z). \n";
                continue;
            }else{
                guess.push_back(ch);
                if (guess.size()>=4)
                {
                    if(guess[0]==word.getLetter(0) && guess[1]==word.getLetter(1) && guess[2]==word.getLetter(2) && guess[3]==word.getLetter(3)){
                        std::cout<<"Congratulations! You guessed the correct word!"<<std::endl;
                        break;
                    }else{
                        auto [number_match,position_match] = word.check_guess(guess);
                        std::cout<<"You have "<<position_match<<" Bulls and "<<number_match<<" cow(s)."<<std::endl;
                    }
                    guess.clear();
                    break;
                }
            }

        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


