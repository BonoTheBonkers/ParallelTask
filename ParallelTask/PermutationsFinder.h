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
	high_resolution_clock::time_point lastStartTime;
	high_resolution_clock::time_point lastEndTime;
	duration<double> lastDuration;

private:
	//@TODO add public variables here


public:
	PermutationsFinder();
	~PermutationsFinder();

	int FindPermutations();

private:
	void Display(int a[], int n);
	void CheckPermutationCombinations(int a[], int n);
	void FindDigitsPermutations(int a[], int n);

	void OnCalculationsStarted();
	void OnCalculationsEnded();
};