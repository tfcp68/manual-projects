#include "placement.h"
#include "vector"
#include <iostream>
#include "cmath"
#include <cassert>
#include <stdlib.h>

#define TEST_CASE(fn)\
std::cout << "    Running " << #fn << "...";                                                            \
fn();                                                                                              \
std::cout << #fn << " Complete. " << std::endl;                                                                     \
//std::cout << "================================================================================" << std::endl;

using namespace std;

void Test_RepetitionPlacement(){
    int a = RepetitionPlacement(5,5);
    assert(a == pow(5,5));
}

void Test_RepetitionPlacement_rand(){
    bool BOOL = true;
    for (int i = 0; i < 40; ++i) {
        int a = rand()%10+1;
        int b = rand()%10+1;
        int c = RepetitionPlacement(b,a);
        if (c != pow(a,b)){
            BOOL = false;
        }
    }
    assert(BOOL);
}

void Test_generation_rand(){
    bool BOOL = true;
    vector<vector<int> > k;
    for (int i = 0; i < 1000; ++i) {
        int a = rand()%3+2;
        int b = rand()%3+2;
        k = RepetitionPlacement_generation(b,a);
        int c = RepetitionPlacement(b,a);
        if (c != k.size()){
            BOOL = false;
        }
        k.clear();
    }
    assert(BOOL);
}

void Test_Repetition_placement_number_rand(){
    bool BOOL = true;
    for (int i = 0; i < 100; ++i) {
        int a = std::rand()%5+2;
        int b = std::rand()%5+2;
        vector<vector<int> > k;
        k = RepetitionPlacement_generation(b,a);
        int c = RepetitionPlacement(b,a);
        int f = std::rand()%c;
        vector<int> l = RepetitionPlacement_number(b,a,f);
        vector<int> a1 = k[f];
        if (a1 != l){
            BOOL = false;
        }
        k.clear();
    }
    assert(BOOL);
}

void Test_Repetition_placement_plac_rand(){
    bool BOOL = true;
    for (int i = 0; i < 100; ++i) {
        int a = std::rand()%5+2;
        int b = std::rand()%5+2;
        vector<vector<int> > k;
        k = RepetitionPlacement_generation(b,a);
        int c = RepetitionPlacement(b,a);
        int f = std::rand()%c;
        vector<int> l = RepetitionPlacement_number(b,a,f);
        vector<int> a1 = k[f];
        int a2 = RepetitionPlacement_plac(b,a,l);
        if (a2 != f){
            BOOL = false;
        }
        k.clear();
    }
    assert(BOOL);
}

void Test_Repetition_placement_plus_1(){
    bool BOOL = true;
    for (int i = 0; i < 100; ++i) {
        int a = std::rand()%5+2;
        int b = std::rand()%5+2;
        vector<vector<int> > k;
        k = RepetitionPlacement_generation(b,a);
        int c = RepetitionPlacement(b,a);
        int f = std::rand()%c;
        vector<int> l = RepetitionPlacement_number(b,a,f);
        vector<int> l1 = RepetitionPlacement_plac_plus_1(b,a,l);
        vector<int> a1 = k[f];
        int a2 = RepetitionPlacement_plac(b,a,l);
        int a3= RepetitionPlacement_plac(b,a,l1);
        if (a3-a2 != 1){
            BOOL = false;
        }
        k.clear();
    }
    assert(BOOL);
}

signed main(){
    TEST_CASE(Test_RepetitionPlacement);
    TEST_CASE(Test_RepetitionPlacement_rand);
    TEST_CASE(Test_generation_rand);
    TEST_CASE(Test_Repetition_placement_number_rand);
    TEST_CASE(Test_Repetition_placement_plac_rand);
    TEST_CASE(Test_Repetition_placement_plus_1);
}