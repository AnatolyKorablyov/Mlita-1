#include "stdafx.h"
#include "..\\Lab1.6Domino\ResultProcessing.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_CASE(SimpleCheck)
{
	std::vector <std::vector<int>>  a = { { 1,2 },{ 3,4 },{ 4,1 },{ 1,6 },{ 1,0 } };
	BOOST_CHECK_EQUAL(ResultProcessing(5,a), "611443");
}
BOOST_AUTO_TEST_SUITE_END()


