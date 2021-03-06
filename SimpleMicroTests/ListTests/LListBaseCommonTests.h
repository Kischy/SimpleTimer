#ifndef LLISTBASECOMMONTESTS_H
#define LLISTBASECOMMONTESTS_H

#include <gtest/gtest.h>
#include <memory>
#include "LList/LListBase.h"

class LListBaseTests : public testing::TestWithParam< std::shared_ptr<smpmcr::LListBase<int>> >
{
    public:
    std::shared_ptr<smpmcr::LListBase<int>> testList = GetParam();
    

};

class LListBaseEraseTests : public testing::TestWithParam< std::shared_ptr<smpmcr::LListBase<long>> >
{
    public:
    std::shared_ptr<smpmcr::LListBase<long>> testList = GetParam();

    bool (*comparisonFunc)(const long&, const long&) = [](const long& lhs, const long& rhs) {return lhs == rhs;};


    LListBaseEraseTests()
    {
        testList->pushFront(1);
        testList->pushFront(2);
        testList->pushFront(1);
        testList->pushFront(3);
        testList->pushFront(1);
        testList->pushFront(1);
        testList->pushFront(5);
    }
    

};



class LListBaseIteratorAndFrontTests : public testing::TestWithParam< std::shared_ptr<smpmcr::LListBase<int>> >
{
    public:
    std::shared_ptr<smpmcr::LListBase<int>> testList = GetParam();



    LListBaseIteratorAndFrontTests()
    {
        for(int i = 0; i < 10; ++i)
        {
            testList->pushFront(i);
        }
    }
    

};

class IntHolder
{
public:
    IntHolder()
    {
        holderValue = 0;
    }

    IntHolder(int value)
    {
        this->holderValue = value;
    }

    int holderValue;  

    bool operator==(const IntHolder& rhs)
    {
        return this->holderValue == rhs.holderValue;
    }
};


class LListBaseIteratorArrowOperatorTests : public testing::TestWithParam< std::shared_ptr<smpmcr::LListBase<IntHolder>> >
{
public:

    std::shared_ptr<smpmcr::LListBase<IntHolder>> testList = GetParam();

    LListBaseIteratorArrowOperatorTests()
    {
        for(int i = 0; i < 10; ++i)
        {
            testList->pushFront(IntHolder(i));
        }
    }

};




#endif //LLISTBASECOMMONTESTS_H