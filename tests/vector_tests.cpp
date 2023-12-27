#include "../src/Vector.hpp"
#include <gtest/gtest.h>

class VectorTest : public ::testing::Test {
public:
  container::Vector<int> lEmpty{};
  container::Vector<int> lFilled;

protected:
  void SetUp() override {
      lFilled = {1, 2, 3};
  }
  
};

TEST_F(VectorTest, CreateVector) {
  EXPECT_TRUE(lEmpty.empty());
  EXPECT_EQ(lEmpty.size(), 0);
  EXPECT_EQ(lEmpty.begin(), lEmpty.end());
}

TEST_F(VectorTest, InsertAtEnd) {
  int toInsert = 10;
  lFilled.push_back(toInsert);

  auto index = lFilled.size() - 1;
  EXPECT_EQ(lFilled[index], toInsert);
}

TEST_F(VectorTest, InsertAtBeginning) {
  int toInsert = 20;
  lFilled.insert(lFilled.begin(), toInsert);

  EXPECT_EQ(lFilled[0], toInsert);
}

TEST_F(VectorTest, InsertAtMiddle) {
  int toInsert = 40;
  int indexMiddle = lFilled.size() / 2;

  lFilled.insert(indexMiddle, toInsert);

  EXPECT_EQ(lFilled[indexMiddle], toInsert);
}


using VectorT = container::Vector<int> ;


TEST_F(VectorTest, EraseAtEnd) {
  VectorT vExpected{1, 2};
  auto indexToErase = lFilled.size() - 1;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == vExpected) << lFilled.toString("filled") << vExpected.toString("Expected");
}

TEST_F(VectorTest, EraseAtBeginning) {
  VectorT vExpected{2, 3};
  auto indexToErase = 0;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == vExpected) << lFilled.toString("filled") << vExpected.toString("Expected");
}

TEST_F(VectorTest, EraseAtMiddle) {
  VectorT vExpected{1, 3};
  auto indexToErase = lFilled.size() / 2;

  lFilled.erase(indexToErase);
  
  EXPECT_TRUE(lFilled == vExpected) << lFilled.toString("filled") << vExpected.toString("Expected");
}

TEST_F(VectorTest, At) {
  EXPECT_EQ (lFilled.at(0), 1);
}

TEST_F(VectorTest, AtOutRange) {
  auto indexError = lFilled.size();

  EXPECT_THROW (lFilled.at(indexError), std::out_of_range);
}

TEST_F(VectorTest, Size) {
  EXPECT_EQ (lFilled.size(), 3);
}

TEST_F(VectorTest, Copy) {
  lEmpty = lFilled;
  EXPECT_EQ (lFilled, lEmpty);
}

TEST_F(VectorTest, Move) {
  auto vExpected = lFilled;

  lEmpty = std::move(lFilled);

  EXPECT_EQ (lEmpty, vExpected);
  EXPECT_EQ (lFilled.size(), 0);
}

TEST_F(VectorTest, Destructor) {
  lFilled.~Vector();
  EXPECT_EQ (lFilled.size(), 0);
}
