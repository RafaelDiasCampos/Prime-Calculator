#pragma once
#include <iostream>
#include <vector>

class Primes
{
public:
	std::vector<unsigned long long> getPrimes(unsigned long long maxPrime);
	const static int ALG_SIEVE_ERATOSTHENES = 1;
	const static int ALG_SIEVE_SUNDARAM = 2;
	const static int ALG_SIEVE_ATKIN = 3;
	int selectedAlgorithm = ALG_SIEVE_SUNDARAM;
private:
	std::vector<unsigned long long> calculateSieveEratosthenes();
	std::vector<unsigned long long> calculateSieveSundaram();
	std::vector<unsigned long long> calculateSieveAtkin();
	unsigned long long maxPrime;
};

