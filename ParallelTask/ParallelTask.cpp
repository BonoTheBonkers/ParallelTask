#include "pch.h"
#include <iostream>

#include "PermutationsFinder.h"


PermutationsFinder* finder;

int main()
{
	finder = new PermutationsFinder();
	const int PermutationsFound = finder->FindPermutations();
    std::cout << "Hello Piotrek!\n";
	
	std::cin.get();
	delete finder;
	finder = NULL;
}