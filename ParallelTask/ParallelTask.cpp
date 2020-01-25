#include "pch.h"
#include <iostream>
#include <thread>

#include "PermutationsFinder.h"

int main()
{
	int inShouldPrint = 0;
	cout << "Do you want to print matching results? (type '1' to print)" << endl;
	cin >> inShouldPrint;

	int inShouldPerformMultithread = 0;
	cout << endl << "Do you want to run job multithreaded? (type '1' to run multithreaded)" << endl;
	cin >> inShouldPerformMultithread;

	PermutationsFinder::DoJob(inShouldPrint == 1, inShouldPerformMultithread == 1);
	
	return 0;
}