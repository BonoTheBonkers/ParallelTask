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

	static void DoJob();

private:
	static int FindMatchingDigitsAndOperatorsPermutations(int *a, int n);
	static int CheckIthPermutation(int n, int i);
	static int CheckPermutationOperatorsCombinations(int *a, int n);
};