/*
[14] Write a program that takes an input value n and then finds the first n primes.
*/
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false; // Found a divisor, not prime
    }
    return true; // No divisors found, it's prime
}


int main(){
    std::vector<int> primes;
    int number;
    std::cout << "Enter the number of prime numbers to find:" << std::endl;
    std::cin >> number;
    if(number < 1){
        std::cout << "Please enter a positive integer greater than 0." << std::endl;
        return 1; // Exit the program with an error code
    }

    int count = 0;
    int i = 2; // Start checking for primes from 2
    while(count < number){
        if(is_prime(i)){
            primes.push_back(i);
            count++;
        }
        i++;
    }

    std::cout << "First " << number << " prime numbers:" << std::endl;
    for(int prime : primes){
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}

    
