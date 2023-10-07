#include "AVL_Tree.h"
#include <vector>
#include <assert.h>

int START_COUNTER = 1;
int FINAL_COUNTER = 10;


#define TEST_CASE(fn)\
std::cout << "    Running " << #fn << "...";                                                            \
fn();                                                                                              \
std::cout << #fn << " Complete. " << std::endl;


void CreateTree(){
    N *root = nullptr;
    for(int i = START_COUNTER;i < FINAL_COUNTER; i++){
        root = Ins(root, i);
    }
    std::vector<int> T = Traverse(root);
    std::vector<int> Checker;
    for(int i = START_COUNTER;i < FINAL_COUNTER; i++){
        Checker.push_back(i);
    }
    assert(T == Checker);
}

void DeleteTree(){
    N *root = nullptr;
    for(int i = START_COUNTER;i < FINAL_COUNTER; i++){
        root = Ins(root, i);
    }
    for(int i = START_COUNTER;i < FINAL_COUNTER; i++){
        root = D(root, i);
    }
    assert(root == nullptr);
}


void FindTree(){
    N *root = nullptr;
    for(int i = START_COUNTER;i < FINAL_COUNTER; i++){
        root = Ins(root, i);
    }
    for(int i = START_COUNTER; i < FINAL_COUNTER; i++) {
        assert(Search(root, i) == i);
    }

}

void FindNodeHand(){
    N *root = nullptr;
    for(int i = 1;i < 11; i++){
        root = Ins(root, i);
    }

}


signed main(){
    TEST_CASE(CreateTree)
    TEST_CASE(DeleteTree)
    TEST_CASE(FindTree)
}