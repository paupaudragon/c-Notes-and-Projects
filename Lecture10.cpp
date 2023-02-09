#include<cassert>
#include<iostream> 
#include<gtest/gtest.h> // have to put gtest/ here, because don't want to we are including all from gtest, but we only need some. 

int factorial(unsigned int number){
    if(number==0)
        return 1; 
    
    return number*factorial(number-1); 
}

TEST(FactorialTest, HandleZero){

    EXPECT_EQ(1, factorial(0))<<"Failed factorial(0)";
}

TEST(FactorialTest, HandleNormal){

    EXPECT_EQ(1, factorial(1))<<"Failed factorial(1)";
    EXPECT_EQ(2, factorial(2))<<"Failed factorial(2)";
    EXPECT_EQ(40320, factorial(8))<<"Failed factorial(8)";
}