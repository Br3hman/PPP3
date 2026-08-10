/*
[12] Create a program to find all the prime numbers between 1 and 100. 
One way to do this is to write a function that will check if a number 
is prime (i.e., see if the number can be divided by a prime number 
smaller than itself) using a vector of primes in order 
(so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). 
Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, 
and stores each prime found in a vector. Write another loop that lists the primes you found. 
You might check your result by comparing your vector of prime numbers with primes. Consider 2 the first prime. 
[13] Create a program to find all the prime numbers between 1 and 100. 
There is a classic method for doing this, called the “Sieve of Eratosthenes.” 
If you don’t know that method, get on the Web and look it up. Write your program using this method.
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
    std::vector<bool> primes(100,true);
    std::vector<int> prime_numbers;
    for (int i = 0; i < 100; ++i) {
        primes[i] = is_prime(i);
        if (primes[i]) {
            prime_numbers.push_back(i);
        }
    }
    std::cout<<"size of prime_numbers:"<<prime_numbers.size()<<std::endl;
    for (int prime : prime_numbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}

    
