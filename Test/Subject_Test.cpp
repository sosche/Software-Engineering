//
// Created by stud on 08.05.19.
//
#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Subject.h"
#undef protected
#undef private

#include <sstream>

class SubjectTest : public ::testing::Test{
protected:
    Subject *m_Subject;
    Observer *m_Observer;

    virtual void SetUp()
    {
        m_Subject = new Subject;
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete m_Subject;
    }
};

TEST_F(SubjectTest, attach)
{
    m_Subject->attach(m_Observer); //Method pushes a object "m_Observer" in vector of class subject
    EXPECT_FALSE(m_Subject->observers.empty()); //Vector should have one element in it
}


TEST_F(SubjectTest, detach)
{
    Observer * oberserverTwo;
    m_Subject->attach(oberserverTwo);
    m_Subject->detach(oberserverTwo);
    m_Subject->detach(m_Observer);//EXPECT_FALSE(m_Subject->observers.empty()); //checks if the vector is empty
    EXPECT_TRUE(m_Subject->observers.empty());
}

TEST_F(SubjectTest, notify)
{
    EXPECT_NO_THROW(m_Subject->notify());
}