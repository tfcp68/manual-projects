#include <stdlib.h>
#include <iostream>
#include "BinaryTree.h"
#include <cassert>
#include <vector>
#include <algorithm>




#define TEST_CASE(fn)\
std::cout << "    Running " << #fn << "...";                                                            \
fn();                                                                                              \
std::cout << #fn << " Complete. " << std::endl;                                                                     \
//std::cout << "================================================================================" << std::endl;

void Test_insert(){
    BinaryTree<int> a;
    a.add_node(1);
    a.add_node(1);
    a.add_node(25);
    a.add_node(-5);
    assert(a.root->value == 1);
    assert(a.root->left->value == -5);
    assert(a.root->right->value == 1);
    assert(a.root->right->right->value == 25);
}

void Test_erase(){
    BinaryTree<int> a;
    a.add_node(1);
    a.add_node(1);
    a.add_node(25);
    a.add_node(-5);
    a.delete_node(1);
    a.delete_node(25);
    assert(a.root->value == 1);
    assert(a.root->left->value == -5);
}

void Test_insert_random(){
    BinaryTree<int> a;
    a.add_node(1);
    vector<int> v;
    for (int i = 0; i < 100; i++){
        int k = std::rand()%30;
        a.add_node(k);
        v.push_back(k);
   }
    v.push_back(1);
    a.tree_traversal();
    assert(a.list.size() == v.size());
}

void Test_erase_random(){
    BinaryTree<int> a;
    a.add_node(1);
    vector<int> v;
    for (int i = 0; i < 100; i++){
        int k = std::rand()%30;
        a.add_node(k);
        v.push_back(k);
    }
    v.push_back(1);
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 101; i++){
        a.delete_node(v[0]);
        v.erase(v.begin());
    }
    a.tree_traversal();
    assert(a.list.size() == v.size());
}

void Test_erase_random_plus() {
    BinaryTree<int> a;
    a.add_node(1);
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        int k = std::rand() % 30;
        a.add_node(k);
        v.push_back(k);
    }
    v.push_back(1);
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 101; i++) {
        a.delete_node(v[0]);
        v.erase(v.begin());
    }
    for (int i = 0; i < 100; i++) {
        int k = std::rand() % 30;
        a.delete_node(k);
    }
    a.tree_traversal();
    assert(a.list.size() == v.size() );
}


signed main(){
    TEST_CASE(Test_insert)
    TEST_CASE(Test_erase)
    TEST_CASE(Test_insert_random)
    TEST_CASE(Test_erase_random)
    TEST_CASE(Test_erase_random_plus)
}