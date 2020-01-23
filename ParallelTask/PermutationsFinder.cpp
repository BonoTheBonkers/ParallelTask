#include "pch.h"
#include "PermutationsFinder.h"

using namespace std;

PermutationsFinder::PermutationsFinder()
{
}

PermutationsFinder::~PermutationsFinder()
{
}

// Function to display the array 
void PermutationsFinder::Display(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

void PermutationsFinder::CheckPermutationCombinations(int a[], int n)
{

}

// Function to find the permutations 
void PermutationsFinder::FindDigitsPermutations(int a[], int n)
{
	// Sort the given array 
	sort(a, a + n);

	// Find all possible permutations 
	cout << "Possible permutations are:\n";
	do {
		CheckPermutationCombinations(a, n);
	} while (next_permutation(a, a + n));
}

int PermutationsFinder::FindPermutations()
{
	OnCalculationsStarted();

	int digits[] = {0,1,2,3,4,5,6,7,8,9};

	int n = sizeof(digits) / sizeof(digits[0]);

	FindDigitsPermutations(digits, n);

	OnCalculationsEnded();

	return 0;
}

void PermutationsFinder::OnCalculationsStarted()
{
	lastStartTime = high_resolution_clock::now();
}

void PermutationsFinder::OnCalculationsEnded()
{
	lastEndTime = high_resolution_clock::now();
	lastDuration = lastEndTime - lastStartTime;
	std::cout << "Latest job duration: " << lastDuration.count() << " seconds.";
}
