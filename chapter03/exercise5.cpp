/*
[5] Write a program to play a numbers guessing game. 
The user thinks of a number between 1 and 100 and your 
program asks questions to figure out what the number is 
(e.g., “Is the number you are thinking of less than 50?”). 
Your program should be able to identify the number after 
asking no more than seven questions.
*/
#include <iostream>
//#include <vector>
//#include <algorithm>

int main(){
    int min{1}, max{100};
    int mid{51};
    std::string answer;
    std::cout << "thinks of a number between 1 and 100, I'll try to guess it!"<<std::endl;
    std::cout << "I will have seven questions to try find the answer"<<std::endl;
    std::cout << "Question 1: Is the number you are thinking of less than "<< mid <<"? (yes/no)"<<std::endl;
    int level{1};
    while(std::cin >> answer){

        if(answer=="yes" || answer=="Yes" || answer=="YES" || answer=="y" || answer=="Y"){
            max = mid-1; // Update the maximum value to the midpoint
        }
        else if(answer=="no" || answer=="No" || answer=="NO" || answer=="n" || answer=="N"){
            min = mid; // Update the minimum value to the midpoint
        }
        else{
            std::cout << "Invalid input. Please answer with 'yes' or 'no'." << std::endl;
            continue; // Skip the rest of the loop and ask the question again
        }

        level++;
        if (level>=8)
        {
             std::cout<<"I couldnt guess:"<<std::endl;
             break;
        }else{
            std::cout<<"Level:"<<level<<" where ("<<min<<","<<max<<")"<<std::endl;
            if (max-min<=2)
            {
                std::cout<<"My guess is your answer is:"<<min+1<<std::endl;
                break;
            }else{
            mid = (min+max)/2;
            std::cout << "Question "<< level <<": Is the number you are thinking of less than "<< mid <<"? (yes/no)"<<"("<<min<<","<<max<<")"<<std::endl;
            }
            
        } 
    }
    
    return 0;
}