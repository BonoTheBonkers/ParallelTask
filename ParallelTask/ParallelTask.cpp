#include "pch.h"
#include <iostream>
#include <thread>

#include "PermutationsFinder.h"

int main()
{
	int inShouldPrint;
	cout << "Do you want to print matching results? (type '1' to print)" << endl;
	cin >> inShouldPrint;

	PermutationsFinder::DoJob(inShouldPrint == 1);
	
	//return 0;
}