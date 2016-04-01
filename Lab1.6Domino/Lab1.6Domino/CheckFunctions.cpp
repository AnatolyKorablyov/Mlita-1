#include "stdafx.h"
#include "CheckFunctions.h"
bool IsNumber(string const &lineStr)
{
	return all_of(lineStr.begin(), lineStr.end(), [](char symbol) {return isdigit(symbol);});
}

bool CheckOnValidValues(string const &lineStr)
{
	return (atoi(lineStr.c_str()) > 6 || atoi(lineStr.c_str()) < 0);
}