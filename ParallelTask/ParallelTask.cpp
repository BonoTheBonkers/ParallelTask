#include "pch.h"
#include <iostream>
#include <thread>

#include "PermutationsFinder.h"

int main()
{
	int inShouldPrint = 0;
	cout << "Do you want to print matching results? ('1' to print, '0' to not print)" << endl;
	cin >> inShouldPrint;

	int inShouldPerformMultithread = 0;
	cout << endl << "Do you want to run job in multithread mode? ('1' to mutli, '0' single thread)" << endl;
	cin >> inShouldPerformMultithread;

	PermutationsFinder::DoJob(inShouldPrint == 1, inShouldPerformMultithread == 1);
	
	return 0;
}