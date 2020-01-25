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

	static void DoJob(bool shouldPrintMatchingResults = false, bool runParallel = true);

private:
	static void FindMatchingDigitsAndOperatorsPermutations(int *digitsArray, int n, int& outMatchingResults, bool shouldPrintMatchingResults, bool runParallel);
	static void CheckIthPermutation(int n, int i, int& outMatchingResults, bool shouldPrintMatchingResults);
	static void CheckPermutationOperatorsCombinations(int *digitsArray, int n, int& outMatchingResults, bool shouldPrintMatchingResults);
};