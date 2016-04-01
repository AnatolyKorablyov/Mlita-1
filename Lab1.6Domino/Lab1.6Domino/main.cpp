#include "stdafx.h"
#include "Definition.h"
#include "WriteMaxNumberInFile.h"

#include "FillingArrays.h"
#include "CheckFunctions.h"
#include "ResultProcessing.h"
using namespace std;
typedef vector< vector<int> > VecInt;


ErrorCode StartProgram()
{
	ifstream inputFile;
	string inputFileName = "input.txt";
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		return ErrorCode::CANT_OPEN_INPUT_FILE;
	}
	string leftPoint;
	string rightPoint;
	string firstLineStr;
	inputFile >> firstLineStr;
	int countDominoForLeft = 0;
	int countDominoForRight = 0;
	int quantityLineStr = 0;
	VecInt arrayDomino(MAX_QUANTITY_DOMINO + 1, vector<int>(2));
	int quantityDomino = 0;
	while (!inputFile.eof())
	{

		inputFile >> leftPoint >> rightPoint;
		if (atoi(firstLineStr.c_str()) > 20)
		{
			return ErrorCode::THE_NUMBER_OF_DOMINO_MORE_20;
		}
		else if (atoi(firstLineStr.c_str()) < 2)
		{
			return ErrorCode::THE_NUMBER_OF_DOMINO_LESS_2;
		}
		quantityDomino = atoi(firstLineStr.c_str());
		quantityLineStr++;
		if (!IsNumber(leftPoint) || !IsNumber(rightPoint))
		{
			return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
		}
		if (CheckOnValidValues(leftPoint) || CheckOnValidValues(rightPoint))
		{
			return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
		}
		arrayDomino[countDominoForLeft][countDominoForRight] = atoi(leftPoint.c_str());
		countDominoForRight++;
		arrayDomino[countDominoForLeft][countDominoForRight] = atoi(rightPoint.c_str());
		countDominoForRight--;
		countDominoForLeft++;
	}
	if (quantityDomino != countDominoForLeft)
	{
		return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
	}
	if (ResultProcessing(quantityDomino, arrayDomino))
	{
		return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
	}
	return ErrorCode::ALL_IS_OK;
}


int main()
{
	switch (StartProgram())
	{
	case CANT_OPEN_INPUT_FILE:
		cout << "cant open input file";
		WriteMaxNumberInFile("cant open input file");
		return 1;
	case CANT_OPEN_OUTPUT_FILE:
		cout << "cant open input file";
		WriteMaxNumberInFile("cant open input file");
		return 1;
	case INCORRECT_INPUT_DATA_IN_FILE:
		WriteMaxNumberInFile("incorrect input data in file");
		cout << "incorrect input data in file";
		return 1;
	case THE_NUMBER_OF_DOMINO_LESS_2:
		WriteMaxNumberInFile("THE_NUMBER_OF_DOMINO_LESS_2");
		cout << "THE_NUMBER_OF_DOMINO_LESS_2";
		return 1;
	case THE_NUMBER_OF_DOMINO_MORE_20:
		WriteMaxNumberInFile("THE_NUMBER_OF_DOMINO_MORE_20");
		cout << "THE_NUMBER_OF_DOMINO_MORE_20";
		return 1;
	case ALL_IS_OK:
		return 0;
	}
}