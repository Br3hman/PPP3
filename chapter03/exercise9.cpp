/*
[9] There is an old story that the emperor wanted to thank the inventor of the game 
of chess and asked the inventor to name his reward. The inventor asked for one grain 
of rice for the first square, 2 for the second, 4 for the third, and so on, doubling 
for each of the 64 squares. That may sound modest, but there wasn’t that much rice in 
the empire! Write a program to calculate how many squares are required to give the 
inventor at least 1000 grains of rice, at least 1,000,000 grains, and at least 
1,000,000,000 grains. You’ll need a loop, of course, and probably an int to keep track 
of which square you are at, an int to keep the number of grains on the current square, 
and an int to keep track of the grains on all previous squares. We suggest that you write 
out the value of all your variables for each iteration of the loop so that you can see what’s going on.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath> // Required for std::pow



int main(){
    int current_square{0}, previous_square{1}, sum_previous_all{0};
    int index1{0}, index2{0}, index3{0};

    for(int i=1; i<=64; ++i){
        if(i==1){
            current_square = 1;
            sum_previous_all = 1;
        }else{
            current_square = previous_square*2;
            sum_previous_all+=current_square;
        }

        if(sum_previous_all>1000 && sum_previous_all<=std::pow(2,10)){
            index1 = i;    
        }else if(sum_previous_all>1000000 && sum_previous_all<=std::pow(2,20)){
            index2 = i;
        }else if(sum_previous_all>1000000000 && sum_previous_all<=std::pow(2,30)){
            index3 = i;
        }

        std::cout<<"Square:"<<i<<" Current Square:"<<current_square<<" Sum of all previous squares:"<<sum_previous_all<<std::endl;
        previous_square = current_square;
    }
    std::cout<<"The first square that exceeds 1000 is:"<<index1<<std::endl
             <<"The first square that exceeds 10000 is:"<<index2<<std::endl
             <<"The first square that exceeds 1000000000 is:"<<index3<<std::endl;
             
    return 0;
}