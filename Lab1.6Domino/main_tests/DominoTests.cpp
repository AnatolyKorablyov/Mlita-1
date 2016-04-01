#include "stdafx.h"
#include "..\\Lab1.6Domino\ResultProcessing.h"
#include <boost/test/unit_test.hpp>

std::string CheckOutputFile(const std::string &fileName)
{
	std::string result;
	std::ifstream fin(fileName);
	fin >> result;
	return result;
}

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_CASE(SimpleCheck)
{
	BOOST_CHECK(ResultProcessing(5, { {1,2},{3,4},{4,1}, {1,6}, {1,0} }) == true);
	BOOST_CHECK_EQUAL(CheckOutputFile("..\\Lab1.6Domino\output.txt"),"611443");
}
BOOST_AUTO_TEST_SUITE_END()


