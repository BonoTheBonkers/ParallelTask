#include "pch.h"
#include "PermutationsFinder.h"

using namespace std;

void PermutationsFinder::DoJob()
{
	high_resolution_clock::time_point startTime = high_resolution_clock::now();

	int digits[] = { 0,1,2,3,4,5,6,7,8,9 };

	int n = sizeof(digits) / sizeof(digits[0]);

	int result = FindDigitsPermutations(digits, n);
	std::cout << "Matching results: " << result << ". \n";

	duration<double> jobDuration = high_resolution_clock::now() - startTime;
	std::cout << "Job duration: " << jobDuration.count() << " seconds.";
}

int PermutationsFinder::FindDigitsPermutations(int *a, int n)
{
	int result = 0;

	sort(a, a + n);

	//@TODO maybe divide into parallel jobs here?
	cout << "Possible permutations are:\n";
	do {
		result += CheckPermutationCombinations(a, n);
	} while (next_permutation(a, a + n));

	return result;
}

int PermutationsFinder::CheckPermutationCombinations(int *a, int n)
{
	int result = 0;

	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < n - 1; ++j)
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
							cout << currentNumber1 << " / " << currentNumber2 << " + " << currentNumber3 << "\n";
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
							cout << currentNumber1 << " + " << currentNumber2 << " / " << currentNumber3 << "\n";
						}
					}
				}
			}
		}
	}

	return result;
}