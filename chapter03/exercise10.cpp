/*
[10] Try to calculate the number of rice grains that the inventor asked for 
in exercise 9 above. You’ll find that the number is so large that it won’t 
fit in an int or a double. Observe what happens when the number gets too 
large to represent exactly as an int and as a double. 
What is the largest number of squares for which you can calculate the 
exact number of grains (using an int)? What is the largest number of 
squares for which you can calculate the approximate number of grains (using a double)?
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath> // Required for std::pow



int main(){
    double current_square{0}, previous_square{1}, sum_previous_all{0};
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
    std::cout<<"The largest number of squares for which you can calculate the exact number of grains (using an int32_t) is:"<<32<<std::endl
             <<"The largest number of squares for which you can calculate the approximate number of grains (using a double) is:"<<64<<std::endl;
             
    return 0;
}