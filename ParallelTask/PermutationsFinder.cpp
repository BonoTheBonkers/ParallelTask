#include "pch.h"
#include "PermutationsFinder.h"
#include <omp.h>
#include <vector>

using namespace std;

void PermutationsFinder::DoJob()
{
	high_resolution_clock::time_point startTime = high_resolution_clock::now();

	#pragma omp parallel
	{
		cout << "Thread number : " << omp_get_thread_num() << " is ready to work!\n";
	}
	cout << "\n";

	int digits[] = { 0,1,2,3,4,5,6,7,8,9 };

	int n = sizeof(digits) / sizeof(digits[0]);

	int result = FindMatchingDigitsAndOperatorsPermutations(digits, n);
	std::cout << "Matching results: " << result << ". \n";

	duration<double> jobDuration = high_resolution_clock::now() - startTime;
	std::cout << "Job duration: " << jobDuration.count() << " seconds.";
}

int PermutationsFinder::FindMatchingDigitsAndOperatorsPermutations(int *a, int n)
{
	int result = 0;

	sort(a, a + n);

	cout << "Possible permutations are:\n";

	int PermuationsAmount = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

	cout << "PermuationsAmount: " << PermuationsAmount << "\n";

	int newValue = 0;

	#pragma omp parallel
	#pragma omp for
	for (int i = 0; i < PermuationsAmount; ++i)
	{
		newValue = CheckIthPermutation(10, i);
		if (newValue > 0)
		{
			result += newValue;
		}
	}

	return result;
}

// Finding ith permutation function is based on this source: 
// https://stackoverflow.com/questions/7918806/finding-n-th-permutation-without-computing-others
int PermutationsFinder::CheckIthPermutation(int n, int i)
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

	return CheckPermutationOperatorsCombinations(perm, n);
}

int PermutationsFinder::CheckPermutationOperatorsCombinations(int *a, int n)
{
	int result = 0;
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
							++result;
							//cout << currentNumber1 << " / " << currentNumber2 << " + " << currentNumber3 << "\n";
						}
					}
				}
				else
				{
					if (currentNumber3 != 0.0f)
					{
						if ((currentNumber1 + currentNumber2 / currentNumber3) == 100.0f)
						{
							++result;
							//cout << currentNumber1 << " + " << currentNumber2 << " / " << currentNumber3 << "\n";
						}
					}
				}
			}
		}
	}

	return result;
}