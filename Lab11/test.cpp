#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TestSortare1, TestPrimulElement)
{
    int a[5] = { 3, 8 ,0, 1 };
    unsigned int n = 4;
    bubbleSort <int>(a, n);
    ASSERT_EQ(a[0], 0);
}
TEST(TestSortare2, TestUltimulElement)
{
    int a[5] = { 3, 8 ,0, 1 };
    unsigned int n = 4;
    bubbleSort <int>(a, n);
    ASSERT_EQ(a[3], 8);
}
TEST(TestSortare3, TestVectorDeDouaElemnte)
{
    int a[3] = { 8,3 };
    unsigned int n = 2;
    bubbleSort <int>(a, n);
    ASSERT_EQ(a[0], a[1]);
}
TEST(TestSortare4, TestElementeConsecutive)
{
    int a[5] = { 3, 3, 8 ,0, 1, };
    unsigned int n = 5;
    bubbleSort <int>(a, n);
    for (unsigned int i = 0; i < 4; i++)
        ASSERT_LE(a[i], a[i + 1]);
}
TEST(TestSortare5, TestElementeSortate)
{
    int a[5] = { 3, 8 ,0, 1, 3 };
    unsigned int n = 5;
    bubbleSort <int>(a, n);
    for (unsigned int i = 0; i < 4; i++)
        ASSERT_LE(a[i], a[i + 1]);
}