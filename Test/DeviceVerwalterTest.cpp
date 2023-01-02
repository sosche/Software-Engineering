#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "DeviceVerwalter.h"
#undef protected
#undef private


class DeviceVerwalterTest: public ::testing::Test
{
protected:
    DeviceVerwalter *deviceVerwalter;
    VorhandeneZutaten *vorhandeneZutaten;

    virtual void SetUp()
    {
        vorhandeneZutaten = new VorhandeneZutaten();
        deviceVerwalter = new DeviceVerwalter(vorhandeneZutaten);
    }

    virtual void TearDown()
    {
        //std::cout.rdbuf(old_buf);
        delete deviceVerwalter;
        delete vorhandeneZutaten;

    }
};

TEST_F(DeviceVerwalterTest, createDevices) {
    EXPECT_EQ(22, deviceVerwalter->myDevices->size());
}

TEST_F(DeviceVerwalterTest,setZutatenVerwalter){
    deviceVerwalter->setZutatenVerwalter(vorhandeneZutaten);
    EXPECT_EQ(deviceVerwalter->myZutatenVerwalter, vorhandeneZutaten);
}

TEST_F(DeviceVerwalterTest, rezeptSchrittZubereiten) {

    Timer * t = Timer::getInstance();
    t->set_Turbo(100000);
    EXPECT_NO_THROW(deviceVerwalter->rezeptSchrittZubereiten("Limettenstuecke",1));

    EXPECT_NO_THROW(deviceVerwalter->rezeptSchrittZubereiten("Eis",1));

    EXPECT_ANY_THROW(deviceVerwalter->rezeptSchrittZubereiten("Blumen",1));
}


TEST_F(DeviceVerwalterTest, entleeren) {
    EXPECT_NO_THROW(deviceVerwalter->entleeren(0));
}

TEST_F(DeviceVerwalterTest, putzen) {
    deviceVerwalter->rezeptSchrittZubereiten("Limettenstuecke",1);
    EXPECT_NO_THROW(deviceVerwalter->putzen());
}

