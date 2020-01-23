#include "pch.h"
#include <iostream>

#include "PermutationsFinder.h"

int main()
{
	const int matchingResultsFound = PermutationsFinder::DoJob();
    std::cout << "Matching results found: " << matchingResultsFound << "!\n";
	
	std::cin.get();
}