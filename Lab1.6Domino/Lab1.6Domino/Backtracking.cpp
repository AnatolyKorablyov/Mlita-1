#include "stdafx.h"
#include "Backtracking.h"
#include "CheckFunctions.h"
#include "FillingArrays.h"
#include "CheckNum.h"

void Backtracking(int const &quantityDomino, VecInt &arrayDomino, vector<int> &bestMaxLenNumber, vector<int> &maxLenNumber, bool &findNum, vector<bool> &checkArray, VecInt &longNumArray, int const &selection)
{
	for (int first = 0; first < quantityDomino; ++first)
	{
		for (int i = 0; i < quantityDomino; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if ((first != i) && (j == 1) && (arrayDomino[first][j] == arrayDomino[i][j]) && checkArray[i] != true)
				{
					maxLenNumber.push_back(arrayDomino[first][j - 1]);
					maxLenNumber.push_back(arrayDomino[first][j]);
					maxLenNumber.push_back(arrayDomino[i][j]);
					maxLenNumber.push_back(arrayDomino[i][j - 1]);
					Initialization(checkArray, findNum, first, i);
				}
				else if ((first != i) && (j == 1) && (arrayDomino[first][j] == arrayDomino[i][j - 1]) && checkArray[i] != true)
				{
					maxLenNumber.push_back(arrayDomino[first][j - 1]);
					maxLenNumber.push_back(arrayDomino[first][j]);
					maxLenNumber.push_back(arrayDomino[i][j - 1]);
					maxLenNumber.push_back(arrayDomino[i][j]);
					Initialization(checkArray, findNum, first, i);
				}
				else if ((first != i) && (j == 0) && (arrayDomino[first][j] == arrayDomino[i][j]) && checkArray[i] != true)
				{
					maxLenNumber.push_back(arrayDomino[first][j + 1]);
					maxLenNumber.push_back(arrayDomino[first][j]);
					maxLenNumber.push_back(arrayDomino[i][j]);
					maxLenNumber.push_back(arrayDomino[i][j + 1]);
					Initialization(checkArray, findNum, first, i);
				}
				else if ((first != i) && (j == 0) && (arrayDomino[first][j] == arrayDomino[i][j + 1]) && checkArray[i] != true)
				{
					maxLenNumber.push_back(arrayDomino[first][j + 1]);
					maxLenNumber.push_back(arrayDomino[first][j]);
					maxLenNumber.push_back(arrayDomino[i][j + 1]);
					maxLenNumber.push_back(arrayDomino[i][j]);
					Initialization(checkArray, findNum, first, i);

				}
				if (findNum)
				{
					findNum = false;
					if (selection)
					{
						CheckNumTwo(arrayDomino, quantityDomino, maxLenNumber, checkArray);
					}
					CheckNum(arrayDomino, quantityDomino, maxLenNumber, checkArray);
					bestMaxLenNumber = maxLenNumber;
					longNumArray.push_back(bestMaxLenNumber);
					reverse(bestMaxLenNumber.begin(), bestMaxLenNumber.end());
					longNumArray.push_back(bestMaxLenNumber);
					maxLenNumber.clear();
					MakeFalse(checkArray);
				}
			}
		}
	}
}
