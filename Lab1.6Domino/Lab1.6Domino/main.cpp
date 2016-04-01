
#include "stdafx.h"
#include "Definition.h"
#include "WriteMaxNumberInFile.h"

#include "FillingArrays.h"
#include "CheckFunctions.h"
#include "ResultProcessing.h"
using namespace std;
typedef vector< vector<int> > VecInt;

ErrorCode CheckErrorCodeForFirstLine(const int &firstLineInt)
{
	if (firstLineInt > MAX_QUANTITY_DOMINO)
	{
		return ErrorCode::THE_NUMBER_OF_DOMINO_MORE_20;
	}
	else if (firstLineInt < MIN_QUANTITY_DOMINO)
	{
		return ErrorCode::THE_NUMBER_OF_DOMINO_LESS_2;
	}
	return ALL_IS_OK;
}
ErrorCode CheckErrorCodeForDomino(const string &leftPoint, const string &rightPoint, const int &leftPointInt, const int &rightPointInt)
{
	if (!IsNumber(leftPoint) || !IsNumber(rightPoint))
	{
		return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
	}
	if (CheckOnValidValues(leftPointInt) || CheckOnValidValues(rightPointInt))
	{
		return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
	}
	return ALL_IS_OK;
}

ErrorCode StartProgram(const string &inputFileName)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		return ErrorCode::CANT_OPEN_INPUT_FILE;
	}
	string leftPoint;
	string rightPoint;
	string firstLineStr;
	inputFile >> firstLineStr;
	unsigned firstLineInt = atoi(firstLineStr.c_str());
	if (CheckErrorCodeForFirstLine(firstLineInt) != ALL_IS_OK)
	{
		return CheckErrorCodeForFirstLine(firstLineInt);
	}
	int countDominoForLeft = 0;
	int countDominoForRight = 0;
	int quantityLineStr = 0;
	VecInt arrayDomino(MAX_QUANTITY_DOMINO + 1, vector<int>(2));
	int quantityDomino = 0;
	while (!inputFile.eof())
	{

		inputFile >> leftPoint >> rightPoint;
		unsigned leftPointInt = atoi(leftPoint.c_str());
		unsigned rightPointInt = atoi(rightPoint.c_str());
		quantityDomino = firstLineInt;
		quantityLineStr++;
		if (CheckErrorCodeForDomino(leftPoint, rightPoint, leftPointInt, rightPointInt) != ALL_IS_OK)
		{
			return CheckErrorCodeForDomino(leftPoint, rightPoint, leftPointInt, rightPointInt);;
		}
		arrayDomino[countDominoForLeft][countDominoForRight] = leftPointInt;
		countDominoForRight++;
		arrayDomino[countDominoForLeft][countDominoForRight] = rightPointInt;
		countDominoForRight--;
		countDominoForLeft++;
	}
	if (quantityDomino != countDominoForLeft)
	{
		return ErrorCode::INCORRECT_INPUT_DATA_IN_FILE;
	}
	ResultProcessing(quantityDomino, arrayDomino);
	return ErrorCode::ALL_IS_OK;
}

int ErrorOutput(const int &ErrorsCode)
{

	switch (ErrorsCode)
	{
	case CANT_OPEN_INPUT_FILE:
		cout << "cant open input file";
		WriteMaxNumberInFile("cant open input file");
		break;
	case CANT_OPEN_OUTPUT_FILE:
		cout << "cant open input file";
		WriteMaxNumberInFile("cant open input file");
		break;
	case INCORRECT_INPUT_DATA_IN_FILE:
		WriteMaxNumberInFile("incorrect input data in file");
		cout << "incorrect input data in file";
		break;
	case THE_NUMBER_OF_DOMINO_LESS_2:
		WriteMaxNumberInFile("THE_NUMBER_OF_DOMINO_LESS_2");
		cout << "THE_NUMBER_OF_DOMINO_LESS_2";
		break;
	case THE_NUMBER_OF_DOMINO_MORE_20:
		WriteMaxNumberInFile("THE_NUMBER_OF_DOMINO_MORE_20");
		cout << "THE_NUMBER_OF_DOMINO_MORE_20";
		break;
	case ALL_IS_OK:
		return 0;
	}
	return 1;
}

int main()
{
	string inputFileName = "input.txt";
	auto result = StartProgram(inputFileName);
	return ErrorOutput(result);
}