/*
[11] Write a program that plays the game “Rock, Paper, Scissors.” 
If you are not familiar with the game do some research (e.g., on 
the Web using Google). Research is a common task for programmers. 
Use a switch-statement to solve this exercise. Also, the machine 
should give random answers (i.e., select the next rock, paper, or 
scissors randomly). Real randomness is too hard to provide just now, 
so just build a vector with a sequence of values to be used as 
“the next value.” If you build the vector into the program, 
it will always play the same game, so maybe you should let the user 
enter some values. Try variations to make it less easy for the user 
to guess which move the machine will make next.
*/
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath> 

char get_user_input() {
    char input;
    std::cout << "Enter \n'r' for Rock,\n'p' for Paper, or\n's' for Scissors \n or '|' to end the game): ";
    std::cin >> input;
    return input;
}

int main(){
    std::vector<std::string> sequence{"Rock", "Paper", "Scissors","Rock","Rock","Paper","Rock","Scissors","Scissors","Paper","paper"};
    int min{0}, max{static_cast<int>(sequence.size())-1};
    int mid{(min+max)/2}, turn{0};
    char answer;
    int current_index{0},last_index{0};
    while ((answer=get_user_input()) && answer!='|')
    {
        if (last_index == max || last_index+turn == max || current_index+turn >= max)
        {
            current_index=last_index/mid;
        }
        else
        {
            current_index=last_index+turn;
        }
        turn++;
        std::cout << "current_index: " << current_index << std::endl << "turn: " << turn << std::endl << "last_index: " << last_index << std::endl;
        
            switch (answer) {
        case 'r':
                std::cout << "You chose Rock. The computer chose " << sequence[current_index] << "." << std::endl;
                turn+=2;

            // Handle what happens when user picks Rock
            break;
        case 'p':
            std::cout << "You chose Paper. The computer chose " << sequence[current_index] << "." << std::endl;
            turn+=3;
            break;
        case 's':
            std::cout << "You chose Scissors. The computer chose " << sequence[current_index] << "." << std::endl;
            turn+=1;
            break;
        default:
            // Handle invalid input
            break;
        }
        
        if(turn>=max){
            turn=0;
            
        }




        last_index=current_index;
    
    }

    return 0;
}

    
