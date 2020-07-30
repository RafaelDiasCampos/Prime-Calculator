#include "Primes.h"

std::vector<unsigned long long> Primes::getPrimes(unsigned long long maxPrime)
{
	this->maxPrime = maxPrime;

	switch (this->selectedAlgorithm) {
		case ALG_SIEVE_ERATOSTHENES: return calculateSieveEratosthenes();
		case ALG_SIEVE_SUNDARAM: return calculateSieveSundaram();
		case ALG_SIEVE_ATKIN: return calculateSieveAtkin();
		default: return std::vector<unsigned long long> ();
	}	
	
}


std::vector<unsigned long long> Primes::calculateSieveEratosthenes() {
	std::vector<bool> isPrime;
	/*
	//Size of the vector. Since even primes don't have to be stored, only half of maxPrime has to be calculated.
	//Doing this changes the position inside the vector of a given number n to: floor(n/2), or simply n/2 since floor is the default behaviour of C++ integer math.
	//And to get from the index i to the number we do: (i * 2 ) + 1
	*/
	unsigned long long vectorSize = ((this->maxPrime - 1) / 2) + 1;

	//Initiliazes vector. Sets all numbers to prime
	for (auto i = 0; i < vectorSize; i++) {
		isPrime.push_back(true);
	}

	//Marks 1 as non prime
	isPrime[1 / 2] = false;


	//Iterates through all numbers
	for (unsigned long long cPrime = 0; cPrime < vectorSize / 2; cPrime++) {

		//If number is prime, mark all its multiples as non prime
		if (isPrime[cPrime]) {
			unsigned long long nPrime = (cPrime * (unsigned long long)2) + 1;
			for (auto cNotPrime = cPrime + nPrime; cNotPrime < vectorSize; cNotPrime += nPrime) {
				isPrime[cNotPrime] = false;
			}
		}
	}

	//Transforms the isPrime vector into primeNumbers vector, with only the primeNumbers in the defined range
	std::vector<unsigned long long> primeNumbers;
	//Adds 2 to the vector (only even prime)
	primeNumbers.push_back(2);
	for (auto i = 0; i < vectorSize; i++) {
		//If number is marked as prime, add it to the vector
		if (isPrime[i]) {
			primeNumbers.push_back((i * (unsigned long long)2) + 1);
		}
	}

	return primeNumbers;
}

std::vector<unsigned long long> Primes::calculateSieveSundaram()
{
	std::vector<bool> isPrime;
	/*
	//Size of the vector. Since even primes don't have to be stored, only half of maxPrime has to be calculated.
	//Doing this changes the position inside the vector of a given number n to: floor(n/2), or simply n/2 since floor is the default behaviour of C++ integer math.
	//And to get from the index i to the number we do: (i * 2 ) + 1
	*/
	unsigned long long vectorSize = ((this->maxPrime - 1) / 2) + 1;

	//Initiliazes vector. Sets all numbers to prime
	for (auto i = 0; i < vectorSize; i++) {
		isPrime.push_back(true);
	}

	//Marks 1 as non prime
	isPrime[1 / 2] = false;

	//Iterates through all numbers
	for (unsigned long long i = 1; i < vectorSize; i++) {
		for (unsigned long long j = i; i + j + (2 * i * j) < vectorSize; j++) {
			isPrime[i + j + (2 * i * j)] = 0;
		}
	}

	//Transforms the isPrime vector into primeNumbers vector, with only the primeNumbers in the defined range
	std::vector<unsigned long long> primeNumbers;
	//Adds 2 to the vector (only even prime)
	primeNumbers.push_back(2);
	for (auto i = 0; i < vectorSize; i++) {
		//If number is marked as prime, add it to the vector
		if (isPrime[i]) {
			primeNumbers.push_back((i * (unsigned long long)2) + 1);
		}
	}

	return primeNumbers;
}

std::vector<unsigned long long> Primes::calculateSieveAtkin()
{
	return std::vector<unsigned long long> ();
}
