#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "VorhandeneZutaten.h"
#undef protected
#undef private


#include <sstream>

class VorhandeneZutatenTest: public ::testing::Test
{
protected:
    VorhandeneZutaten* zv;
    std::basic_streambuf<char>* old_buf;
    std::stringstream ss;

    virtual void SetUp()
    {
        old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
        zv = new VorhandeneZutaten();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(old_buf); // redirect cout back to standard cout
        delete zv;
    }
};

TEST_F(VorhandeneZutatenTest,getAnzahlVorhandeneZutaten)
{
    EXPECT_EQ(18,zv->getAnzahlVorhandeneZutaten());
}

TEST_F(VorhandeneZutatenTest,FileZutatenDotTxtIsAvailable)
{
    // Test redirects the standard cout to another stream (ss)
    // this stream can be read and compared
    // after the test the normal cout is activated again

    ss.clear();
    zv->ZutatenDateiEinlesen("zutaten.txt");
    EXPECT_EQ("Oeffne Zutatendatei",ss.str().substr(0,19));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    //std::string s = ss.str();
    //std::cout << "!!!" << s.substr(0,31) << "!!!" << std::endl;
}

TEST_F(VorhandeneZutatenTest,FileZutatenDotTxtIsNotAvailable)
{
    // Test asserts that an exception is thrown and that the type of the exception is the one expected
    //https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
    EXPECT_THROW(
    {
        try
        {
            zv->ZutatenDateiEinlesen("xxxx.txt");
        }
        catch( std::string e)
        {
            std::cout << e << std::endl;
            EXPECT_EQ("File not found", e.substr(0,14));
            throw;
        }
    }, std::string );
}
TEST_F(VorhandeneZutatenTest,CopyConstructor)
{
    VorhandeneZutaten neu(*zv);
    EXPECT_EQ(neu.zutaten->size(),18);
}

TEST_F(VorhandeneZutatenTest,DummyZutaten)
{
    zv->zutaten->clear();
    zv->DummyZutatenEinfuegen();
    EXPECT_EQ(zv->zutaten->size(),8);
}