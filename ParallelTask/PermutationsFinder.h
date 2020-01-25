#pragma once

#include <iostream>
#include <algorithm>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

class PermutationsFinder
{
public:
	PermutationsFinder() {}
	~PermutationsFinder() {}

	static void DoJob(bool shouldPrintMatchingResults = false);

private:
	static void FindMatchingDigitsAndOperatorsPermutations(int *digitsArray, int arrayLength, int& outMatchingResults);
	static void CheckIthPermutation(int n, int i, int& outMatchingResults);
	static void CheckPermutationOperatorsCombinations(int *digitsArray, int arrayLength, int& outMatchingResults);
};