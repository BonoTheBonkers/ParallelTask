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
void display(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

// Function to find the permutations 
void findPermutations(int a[], int n)
{

	// Sort the given array 
	sort(a, a + n);

	// Find all possible permutations 
	cout << "Possible permutations are:\n";
	do {
		display(a, n);
	} while (next_permutation(a, a + n));
}

int PermutationsFinder::FindPermutations()
{
	lastStartTime = high_resolution_clock::now();

	int digits[] = {0,1,2,3,4,5,6,7,8,9};

	int n = sizeof(digits) / sizeof(digits[0]);

	findPermutations(digits, n);

	return 0;
}