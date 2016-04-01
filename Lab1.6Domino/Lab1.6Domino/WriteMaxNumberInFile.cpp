#include "stdafx.h"
#include "WriteMaxNumberInFile.h"

void WriteMaxNumberInFile(const string  &max)
{
	ofstream output("output.txt");
	output << max;
}