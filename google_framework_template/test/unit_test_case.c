#include <gtest/gtest.h>
#include "../include/my_math.h"
#include "../src/code_to_be_tested.c"

TEST(MytestCategory,MyTest1)
{
	float test_data[]={0,1,2,3,4,5,6,7,8,9,0};
	float average;

	average=calc_average(test_data,10);
	
    EXPECT_EQ(4.5, average);
}


TEST(MytestCategory,MyTest2)
{
	float test_data[]={4.5,12.4,-3.2,5.5,8.3};
	float average;

	average=calc_average(test_data,5);
	
    EXPECT_EQ(5.5, average);
}


