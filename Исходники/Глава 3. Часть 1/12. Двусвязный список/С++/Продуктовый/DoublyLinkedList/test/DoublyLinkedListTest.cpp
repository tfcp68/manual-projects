#include <gtest/gtest.h>
#include "../src/dll.h"



TEST(DoublyLinkedListTest, Test1) {
    DoublyLinkedList<int> list;
    list.pushFront(1);
    EXPECT_EQ(list.getFront(), 1);
    list.pushFront(2);
    EXPECT_EQ(list.getFront(), 2);
}



TEST(DoublyLinkedListTest, Test2) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_EQ(list.getBack(), 1);
    list.pushBack(2);
    EXPECT_EQ(list.getBack(), 2);
}



TEST(DoublyLinkedListTest, Test3) {
    DoublyLinkedList<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.popFront();
    EXPECT_EQ(list.getFront(), 1);
}



TEST(DoublyLinkedListTest, Test4) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.popBack();
    EXPECT_EQ(list.getBack(), 1);
}



TEST(DoublyLinkedListTest, Test5) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_TRUE(list.find(1));
}



TEST(DoublyLinkedListTest, Test6) {
    DoublyLinkedList<int> list;
    list.pushFront(1);
    EXPECT_EQ(list.getFront(), 1);
}



TEST(DoublyLinkedListTest, Test7) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_EQ(list.getBack(), 1);
}



TEST(DoublyLinkedListTest, Test8) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_EQ(list.getSize(), 1);
}



TEST(DoublyLinkedListTest, Test9) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
}



TEST(DoublyLinkedListTest, Test10) {
    DoublyLinkedList<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.popBack();
    EXPECT_EQ(list.getFront(), 2);
}



TEST(DoublyLinkedListTest, Test11) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.popFront();
    EXPECT_EQ(list.getBack(), 2);
}



TEST(DoublyLinkedListTest, Test12) {
    DoublyLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    EXPECT_EQ(list.getBack(), 2);
}



TEST(DoublyLinkedListTest, Test13) {
    DoublyLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 0);
    EXPECT_EQ(list.getFront(), 2);
}



TEST(DoublyLinkedListTest, Test14) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.removeAtIndex(0);
    EXPECT_EQ(list.getFront(), 2);
}



TEST(DoublyLinkedListTest, Test15) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.removeAtIndex(2);
    EXPECT_EQ(list.getBack(), 2);
}



TEST(DoublyLinkedListTest, Test16) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.removeByData(1);
    EXPECT_EQ(list.getFront(), 2);
}



TEST(DoublyLinkedListTest, Test17) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.removeByData(3);
    EXPECT_EQ(list.getBack(), 2);
}



TEST(DoublyLinkedListTest, Test18) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_TRUE(list.find(1));
}



TEST(DoublyLinkedListTest, Test19) {
    DoublyLinkedList<int> list;
    list.pushBack(10);
    list.pushFront(20);
    list.pushBack(30);
    list.pushFront(40);

    auto ourTour = list.tour();
    auto trueTour = vector{40, 20, 10, 30, 10, 20, 40};

    EXPECT_EQ(ourTour, trueTour);
}



TEST(DoublyLinkedListTest, Test20) {

}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}