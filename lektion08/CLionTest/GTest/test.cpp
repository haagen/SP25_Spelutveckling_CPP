#include "gtest/gtest.h"
#include "dice.h"
#include "animal.h"

class AnimalTests: public testing::Test {

    protected:

        animal* a;
    
        void SetUp() override {
            a = new animal("Sture", 'M');    
        }
    
        void TearDown() override {
            delete a;
        }
    
};


TEST_F(AnimalTests, CheckMethods) {
    // Test name
    ASSERT_EQ(a->get_name(), "Sture");

    // Test age
    ASSERT_EQ(a->get_age(), 0);
    a->set_age(10);
    ASSERT_EQ(a->get_age(), 10);

    // Test sex
    ASSERT_EQ(a->getSex(), 'M');
    a->setSex('H');
    ASSERT_EQ(a->getSex(), 'H');
    a->setSex('P');                 // Negative test, it should not change to "P"
    ASSERT_EQ(a->getSex(), 'H');
}

TEST(DiceTests, MinMaxDistribution)
{

    dice d(1, 6);
    int min = 7, max = 0, sum = 0;
    for (int i=0; i<1000; i++) {
        int r = d.roll();
        min = std::min(min, r);
        max = std::max(max, r);
        sum += r;
    }

    int avg = sum / 1000;

    EXPECT_GE(avg, 3);
    EXPECT_LE(avg, 4);
    
    ASSERT_EQ(1, min);
    ASSERT_EQ(6, max);
}
