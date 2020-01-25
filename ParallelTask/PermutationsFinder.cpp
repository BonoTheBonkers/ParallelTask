#include "pch.h"
#include "PermutationsFinder.h"
#include <omp.h>
#include <vector>
#include <thread>

using namespace std;

void PermutationsFinder::DoJob(bool shouldPrintMatchingResults /* = false */, bool runParallel /* = true */)
{
	// sleep for 2 seconds
	std::cout << "Job will start in 4 seconds" << "." << endl << endl;
	using namespace std::this_thread;
	sleep_until(system_clock::now() + seconds(2));

	if (runParallel)
	{
#pragma omp parallel
		{
#pragma omp critical
			{
				cout << "Thread number : " << omp_get_thread_num() << " is ready to work!\n";
			}
		}
	}
	else
	{
		cout << "Running job on single thread!!\n";
	}
	cout << endl << endl;

	sleep_until(system_clock::now() + seconds(2));

	high_resolution_clock::time_point runStartTime = high_resolution_clock::now();

	int digits[] = { 0,1,2,3,4,5,6,7,8,9 };

	int n = sizeof(digits) / sizeof(digits[0]);

	int allMatchingResult = 0;
	FindMatchingDigitsAndOperatorsPermutations(digits, n, allMatchingResult, shouldPrintMatchingResults, runParallel);
	std::cout << endl << endl << "Matching results: " << allMatchingResult << endl << endl;

	duration<double> runDuration = high_resolution_clock::now() - runStartTime;
	std::cout << "Job duration: " << runDuration.count() << " seconds." << endl << endl;

	std::cout << "Application will shutdown in 10 seconds" << "." << endl;
	using namespace std::this_thread;
	sleep_until(system_clock::now() + seconds(10));
}

void PermutationsFinder::FindMatchingDigitsAndOperatorsPermutations(int* digitsArray, int n, int& outMatchingResults, bool shouldPrintMatchingResults, bool runParallel)
{
	int result = 0;

	sort(digitsArray, digitsArray + n);

	if (shouldPrintMatchingResults)
	{
		cout << "Possible permutations are:\n";
	}

	int PermuationsAmount = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

	cout << endl << "PermuationsAmount: " << PermuationsAmount << endl;

	if (runParallel)
	{
#pragma omp parallel
#pragma omp for
		for (int i = 0; i < PermuationsAmount; ++i)
		{
			CheckIthPermutation(10, i, outMatchingResults, shouldPrintMatchingResults);
		}
	}
	else
	{
		for (int i = 0; i < PermuationsAmount; ++i)
		{
			CheckIthPermutation(10, i, outMatchingResults, shouldPrintMatchingResults);
		}
	}
}

// Finding ith permutation function is based on this source: 
// https://stackoverflow.com/questions/7918806/finding-n-th-permutation-without-computing-others
void PermutationsFinder::CheckIthPermutation(int n, int i, int& outMatchingResults, bool shouldPrintMatchingResults)
{
	int j, k = 0;
	int *fact = (int *)calloc(n, sizeof(int));
	int *perm = (int *)calloc(n, sizeof(int));

	fact[k] = 1;
	while (++k < n)
		fact[k] = fact[k - 1] * k;

	for (k = 0; k < n; ++k)
	{
		perm[k] = i / fact[n - 1 - k];
		i = i % fact[n - 1 - k];
	}

	for (k = n - 1; k > 0; --k)
		for (j = k - 1; j >= 0; --j)
			if (perm[j] <= perm[k])
				perm[k]++;

	free(fact);
	free(perm);

	CheckPermutationOperatorsCombinations(perm, n, outMatchingResults, shouldPrintMatchingResults);
}

void PermutationsFinder::CheckPermutationOperatorsCombinations(int *a, int n, int& outMatchingResults, bool shouldPrintMatchingResults)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (i != j)
			{
				int currentNumberIndex = 1;

				float currentNumber1 = 0.0f;
				float currentNumber2 = 0.0f;
				float currentNumber3 = 0.0f;

				for (int x = 0; x < n; ++x)
				{
					if (x == i || x == j)
					{
						++currentNumberIndex;
					}
					if (currentNumberIndex == 1)
					{
						currentNumber1 *= 10.f;
						currentNumber1 += (float)a[x];
					}
					else if (currentNumberIndex == 2)
					{
						currentNumber2 *= 10.f;
						currentNumber2 += (float)a[x];
					}
					else if (currentNumberIndex == 3)
					{
						currentNumber3 *= 10.f;
						currentNumber3 += (float)a[x];
					}
				}

				if (i > j)
				{
					if (currentNumber2 != 0.0f)
					{
						if ((currentNumber1 / currentNumber2 + currentNumber3) == 100.0f)
						{
							++outMatchingResults;
							if (shouldPrintMatchingResults)
							{
#pragma omp critical
								{
									cout << endl << currentNumber1 << " / " << currentNumber2 << " + " << currentNumber3 << " = 100" << endl;
								}
							}
						}
					}
				}
				else
				{
					if (currentNumber3 != 0.0f)
					{
						if ((currentNumber1 + currentNumber2 / currentNumber3) == 100.0f)
						{
							++outMatchingResults;
							if (shouldPrintMatchingResults)
							{
#pragma omp critical
								{
									cout << endl << currentNumber1 << " + " << currentNumber2 << " / " << currentNumber3 << " = 100" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
}