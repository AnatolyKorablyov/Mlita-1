#include "stdafx.h"
#include "FillingArrays.h"

void MakeFalse(vector<bool> &checkArray)
{
	for (size_t i = 0; i < checkArray.size(); i++)
	{
		checkArray[i] = false;
	}
}

void Initialization(vector<bool> &checkArray, bool &findNum, int &first, int &i)
{
	checkArray[i] = true;
	checkArray[first] = true;
	findNum = true;
}


void AddElementsInMaxLenNumer(vector <int> &maxLenNumber, VecInt &arrayDomino, int j, int i, vector<bool> &checkArray, bool &firstNum)
{

	maxLenNumber.push_back(arrayDomino[i][j]);
	maxLenNumber.push_back(arrayDomino[i][j - 1]);
	checkArray[i] = true;
	firstNum = true;
}

void AddElementsInMaxLenNumberThenJIsZero(vector <int> &maxLenNumber, VecInt &arrayDomino, int j, int i, vector<bool> &checkArray, bool &firstNum)
{
	maxLenNumber.push_back(arrayDomino[i][j]);
	maxLenNumber.push_back(arrayDomino[i][j + 1]);
	checkArray[i] = true;
	firstNum = true;
}

void AddElementsInMaxLenNumberThenNoQualZero(vector <int> &maxLenNumber, VecInt &arrayDomino, int j, int i, vector<bool> &checkArray, bool &firstNum)
{
	maxLenNumber.push_back(arrayDomino[i][j - 1]);
	maxLenNumber.push_back(arrayDomino[i][j]);
	checkArray[i] = true;
	firstNum = true;
}
