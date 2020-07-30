// Prime Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Primes.h"
#define PROGRAM_NAME_SEPARATOR "---------"

int main()
{
    std::cout << PROGRAM_NAME_SEPARATOR << "   Prime Numbers Calculator   " << PROGRAM_NAME_SEPARATOR << std::endl;
    std::cout << std::endl;

    std::cout << "Type the maximum number to be calculated (inclusive): ";

    unsigned long long maxPrime = 0;
    std::cin >> maxPrime;

    while (std::cin.fail() || maxPrime <= 0) {
        std::cout << std::endl;
        if (std::cin.fail()) {
            std::cout << "The input has to be a number." << std::endl;
            //Clears input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cout << "The number needs to be greater than 0." << std::endl;
        }
        std::cout << "Type the maximum number to be calculated (inclusive): ";
        std::cin >> maxPrime;
    }

    std::cout << "Calculating primes up to " << maxPrime << " using the Sieve of Eratosthenes." << std::endl;

    Primes primeCalculator;

    //Calculates using Sieve of Eratosthenes
    primeCalculator.selectedAlgorithm = Primes::ALG_SIEVE_ERATOSTHENES;
    auto primesEratosthenes = primeCalculator.getPrimes(maxPrime);

    
    //Prints prime numbers    
    for (auto i : primesEratosthenes) {
        std::cout << i << ", ";
    }

    //Clears last comma and flushes output
    std::cout << "\b\b  " << std::endl << std::flush;
    /*
    */

    std::cout << "Calculating using a different method" << std::endl;

    //Calculates using a different method
    primeCalculator.selectedAlgorithm = Primes::ALG_SIEVE_SUNDARAM;
    auto primesOtherMethod = primeCalculator.getPrimes(maxPrime);

    if (primesEratosthenes.size() == primesOtherMethod.size() &&  std::equal(primesEratosthenes.begin(), primesEratosthenes.end(), primesOtherMethod.begin())) {
        std::cout << "Both vectors have the same numbers." << std::endl;
    }
    else {
        std::cout << "The vectors have different numbers inside them." << std::endl;
        //Prints prime numbers
        for (auto i : primesOtherMethod) {
            std::cout << i << ", ";
        }
    }

}