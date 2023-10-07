#include <stdlib.h>
#include <iostream>
#include "tree_list.h"
#include <cassert>
#include <vector>
#include <algorithm>


#define TEST_CASE(fn)\
std::cout << "    Running " << #fn << "...";                                                            \
fn();                                                                                              \
std::cout << #fn << " Complete. " << std::endl;                                                                     \
//std::cout << "================================================================================" << std::endl;

void Test_insert(){
    Tree_vector<int,int> a(1);
    a.insert(1);
    a.insert(25);
    a.insert(-5);
    assert(a.trees[0] == 1);
    assert(a.trees[1] == -5);
    assert(a.trees[2]== 1);
    assert(a.trees[6] == 25);
}

void Test_erase(){
    Tree_vector<int,int> a(1);
    a.insert(1);
    a.insert(25);
    a.insert(-5);
    a.erase(1);
    a.erase(25);
    assert(a.trees[0] == 1);
    assert(a.trees[1] == -5);
}

void Test_insert_random(){
    Tree_vector<int,int> a(1);
    vector<int> v;
    for (int i = 0; i < 100; i++){
        int k = std::rand()%30+1;
        a.insert(k);
        v.push_back(k);
    }
    v.push_back(1);
    int k = a.print().size();
    assert(k == v.size());
}

void Test_erase_random(){
    Tree_vector<int,int> a(1);
    vector<int> v;
    for (int i = 0; i < 100; i++){
        int k = std::rand()%30+1;
        a.insert(k);
        v.push_back(k);
    }
    v.push_back(1);
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 101; i++){
        a.erase(v[0]);
        v.erase(v.begin());
    }
    a.print();
    int k = a.print().size();
    assert(k == v.size());
}

void Test_erase_random_plus() {
    Tree_vector<int,int> a(1);
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        int k = std::rand() % 30+1;
        a.insert(k);
        v.push_back(k);
    }
    v.push_back(1);
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 101; i++) {
        a.erase(v[0]);
        v.erase(v.begin());
    }
    for (int i = 0; i < 100; i++) {
        int k = std::rand() % 30+1;
        a.erase(k);
    }
    a.print();
    int k = a.print().size();
    assert(k == v.size());
}

void Test_find(){
    Tree_vector<int,int> a(1);
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        int k = std::rand() % 30+1;
        a.insert(k);
        v.push_back(k);
    }
    int k = std::rand() % 30+1;
    assert((a.find(k)==1 and std::count(v.begin(), v.end(),k) !=0 ) or (a.find(k)==0 and
    std::count(v.begin(), v.end(),k) ==0));
};


signed main(){
    TEST_CASE(Test_insert)
    TEST_CASE(Test_erase)
    TEST_CASE(Test_insert_random)
    TEST_CASE(Test_erase_random)
    TEST_CASE(Test_erase_random_plus)
    TEST_CASE(Test_find)
}
