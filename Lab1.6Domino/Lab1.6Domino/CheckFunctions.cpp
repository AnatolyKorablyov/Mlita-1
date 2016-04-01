
#include "stdafx.h"
#include "CheckFunctions.h"
bool IsNumber(string const &lineStr)
{
	return all_of(lineStr.begin(), lineStr.end(), [](char symbol) {return isdigit(symbol); });
}

bool CheckOnValidValues(int const &SymbolInt)
{
	return (SymbolInt > 6 || SymbolInt < 0);
}