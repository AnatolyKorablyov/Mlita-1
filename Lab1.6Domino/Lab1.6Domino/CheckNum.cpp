#include "stdafx.h"
#include "CheckNum.h"
#include "FillingArrays.h"




void CheckNumTwo(VecInt &arrayDomino, int const &quantityDomino, vector <int> &maxLenNumber, vector<bool> &checkArray)
{
	vector <int> maxLenNumberCopy = maxLenNumber;
	bool firstNum = false;
	for (int i = 0; i < quantityDomino; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if ((j == 1) && (maxLenNumber[0] == arrayDomino[i][j]) && checkArray[i] != true)
			{
				reverse(maxLenNumber.begin(), maxLenNumber.end());
				AddElementsInMaxLenNumer(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
			}
			else if ((j == 1) && (maxLenNumber[maxLenNumber.size() - 1] == arrayDomino[i][j]) && checkArray[i] != true)
			{
				AddElementsInMaxLenNumer(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
			}
			else if ((j == 0) && (maxLenNumber[0] == arrayDomino[i][j]) && checkArray[i] != true)
			{
				reverse(maxLenNumber.begin(), maxLenNumber.end());
				AddElementsInMaxLenNumberThenJIsZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
			}
			else if ((j == 0) && (maxLenNumber[maxLenNumber.size() - 1] == arrayDomino[i][j + 1]) && checkArray[i] != true)
			{
				AddElementsInMaxLenNumberThenJIsZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
			}
			if (firstNum)
			{
				firstNum = false;
				CheckNum(arrayDomino, quantityDomino, maxLenNumber, checkArray);
			}
		}
	}
}



void CheckNum(VecInt &arrayDomino, int const &quantityDomino, vector <int> &maxLenNumber, vector<bool> &checkArray)
{
	vector <int> maxLenNumberCopy = maxLenNumber;
	bool firstNum = false;
	for (int i = 0; i < quantityDomino; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{

			if ((maxLenNumber[0] == arrayDomino[i][j]) && checkArray[i] != true)
			{
				reverse(maxLenNumber.begin(), maxLenNumber.end());
				if (j == 0)
				{
					AddElementsInMaxLenNumberThenJIsZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
				}
				else
				{
					AddElementsInMaxLenNumberThenNoQualZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
				}
			}
			else if ((maxLenNumber[maxLenNumber.size() - 1] == arrayDomino[i][j]) && checkArray[i] != true)
			{

				if (j == 0)
				{
					AddElementsInMaxLenNumberThenJIsZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
				}
				else
				{
					AddElementsInMaxLenNumberThenNoQualZero(maxLenNumber, arrayDomino, j, i, checkArray, firstNum);
				}
			}
			if (firstNum)
			{
				firstNum = false;
				CheckNum(arrayDomino, quantityDomino, maxLenNumber, checkArray);
			}
		}
	}
}
