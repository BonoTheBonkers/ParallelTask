#include "pch.h"
#include "PermutationsFinder.h"

using namespace std;

int PermutationsFinder::DoJob()
{
	high_resolution_clock::time_point startTime = high_resolution_clock::now();

	int digits[] = { 0,1,2,3,4,5,6,7,8,9 };

	int n = sizeof(digits) / sizeof(digits[0]);

	FindDigitsPermutations(digits, n);

	duration<double> jobDuration = high_resolution_clock::now() - startTime;
	std::cout << "Latest job duration: " << jobDuration.count() << " seconds.";
	return 0;
}

void PermutationsFinder::Display(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

void PermutationsFinder::FindDigitsPermutations(int a[], int n)
{
	sort(a, a + n);

	//@TODO maybe divide into parallel jobs here?
	cout << "Possible permutations are:\n";
	do {
		CheckPermutationCombinations(a, n);
	} while (next_permutation(a, a + n));
}

void PermutationsFinder::CheckPermutationCombinations(int a[], int n)
{
	//Display(a, n);
	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < n - 1; ++j)
		{
			if (i != j)
			{
				//@TODO do the calculations here, i stands for /, j for +
			}
		}
	}
}