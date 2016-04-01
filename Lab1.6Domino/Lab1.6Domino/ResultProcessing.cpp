#include "stdafx.h"
#include "ResultProcessing.h"
#include "Definition.h"
#include "WriteMaxNumberInFile.h"
#include "Backtracking.h"

bool VecComparator(vector<int> first, vector<int> second)
{
	if (first.size() == second.size())
	{
		for (size_t i = 0; i < first.size(); ++i)
		{
			if (first[i] < second[i])
			{
				return true;
			}
			else if (first[i] > second[i])
			{
				return false;
			}
		}
	}
	if (first.size() < second.size())
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}


std::string  ResultProcessing(int const &quantityDomino, std::vector< std::vector<int> > &arrayDomino)
{
	vector<int> bestMaxLenNumber;
	string glueNumber;
	vector<int> maxLenNumber;
	vector<bool> checkArray(MAX_QUANTITY_DOMINO + 1);
	bool findNum = false;
	VecInt longNumArray;
	bool selection = false;
	Backtracking(quantityDomino, arrayDomino, bestMaxLenNumber, maxLenNumber, findNum, checkArray, longNumArray, selection);
	selection = true;
	Backtracking(quantityDomino, arrayDomino, bestMaxLenNumber, maxLenNumber, findNum, checkArray, longNumArray, selection);
	if (longNumArray.empty())
	{
		string glueNumberReverse;
		vector <int> arrayDominoCopy;
		for (size_t i = 0; i < arrayDomino.size(); i++)
		{
			glueNumber = "";
			glueNumber += to_string(arrayDomino[i][0]);
			glueNumber += to_string(arrayDomino[i][1]);
			glueNumberReverse = glueNumber;
			reverse(glueNumberReverse.begin(), glueNumberReverse.end());
			arrayDominoCopy.push_back(atoi(glueNumber.c_str()));
			arrayDominoCopy.push_back(atoi(glueNumberReverse.c_str()));
		}
		int max = *(std::max_element(arrayDominoCopy.begin(), arrayDominoCopy.end()));
		WriteMaxNumberInFile(to_string(max));
		return to_string(max);
	}
	else
	{
		auto maxEl = *std::max_element(longNumArray.begin(), longNumArray.end(), VecComparator);
		string maxElstr;
		for (auto i : maxEl)
		{
			maxElstr += to_string(i);
		}
		WriteMaxNumberInFile(maxElstr);
		return maxElstr;
	}
}