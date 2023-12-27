#include "../src/List.hpp"
#include <gtest/gtest.h>

class ListTest : public ::testing::Test {
public:
  container::List<int> lEmpty{};
  container::List<int> lFilled;

protected:
  void SetUp() override {
      lFilled = {1, 2, 3};
  }
  
};

TEST_F(ListTest, CreateList) {
  EXPECT_TRUE(lEmpty.empty());
  EXPECT_EQ(lEmpty.size(), 0);
  EXPECT_EQ(lEmpty.begin(), lEmpty.end());
}


 using ListT = container::List<int> ;

TEST_F(ListTest, InsertAtEnd) {
  int toInsert = 10;
  auto lExpected= ListT{1, 2, 3, toInsert};
  
  lFilled.push_back(toInsert);

  EXPECT_EQ(lFilled, lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}


TEST_F(ListTest, InsertAtBeginning) {
  int toInsert = 20;
  auto lExpected= ListT{toInsert, 1, 2, 3};
  
  lFilled.push_front(toInsert);

  EXPECT_EQ(lFilled, lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}


TEST_F(ListTest, InsertAtMiddle) {
  int toInsert = 30;
  auto lExpected= ListT{1, toInsert, 2, 3};
  
  lFilled.push_mid(toInsert);

  EXPECT_EQ(lFilled, lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}

TEST_F(ListTest, EraseAtEnd) {
  ListT lExpected{1, 2};
  auto indexToErase = lFilled.size() - 1;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}

TEST_F(ListTest, EraseAtBeginning) {
  ListT lExpected{2, 3};
  auto indexToErase = 0;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}

TEST_F(ListTest, EraseAtMiddle) {
  ListT lExpected{1, 3};
  auto indexToErase = lFilled.size() / 2;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == lExpected) << lFilled.toString("filled") << lExpected.toString("Expected");
}

TEST_F(ListTest, GettingElement) {
  EXPECT_EQ (lFilled[0], 1);
}

TEST_F(ListTest, AtOutRange) {
  auto indexError = lFilled.size();

  EXPECT_THROW (lFilled[indexError], std::out_of_range);
}

TEST_F(ListTest, Size) {
  EXPECT_EQ (lFilled.size(), 3);
}

TEST_F(ListTest, Copy) {
  lEmpty = lFilled;
  EXPECT_EQ (lFilled, lEmpty);
}

TEST_F(ListTest, Move) {
  auto vExpected = lFilled;

  lEmpty = std::move(lFilled);

  EXPECT_EQ (lEmpty, vExpected);
  EXPECT_EQ (lFilled.size(), 0);
}

TEST_F(ListTest, Destructor) {
  lFilled.~List();
  EXPECT_EQ (lFilled.size(), 0);
}
