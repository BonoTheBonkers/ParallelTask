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

	static int DoJob();

private:
	static void Display(int a[], int n);
	static void FindDigitsPermutations(int a[], int n);
	static void CheckPermutationCombinations(int a[], int n);
};