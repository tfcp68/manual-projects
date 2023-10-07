//
// Created by fedor on 3/25/23.
//
#include <iostream>
#include "AVL_tree.h"
#include <cassert>
#include <vector>
#include <algorithm>




#define TEST_CASE(fn)\
std::cout << "    Running " << #fn << "...";                                                            \
fn();                                                                                              \
std::cout << #fn << " Complete. " << std::endl;                                                                     \
//std::cout << "================================================================================" << std::endl;

int PrintPair(std::pair<int, int> iter){
    return iter.second;
}

AVL_tree<int, int> CreateTree(){
    AVL_tree<int, int> T;
    for(int i = 0;i < 1000; i++){
        T.InsertNode(i, i);
    }
    return T;
}




int START_COUNTER = -5;
int FINAL_COUNTER = 100;


std::vector<int> TraverseTree(AVL_tree<int, int> TREE){
    /*
     * проходит по дереву и заносит данные в массив
     */
    std::vector<int> array;
    auto iter = TREE.begin();
    while(iter != TREE.end()){
        array.push_back(PrintPair(*iter));
        ++iter;
    }
    return array;
}


AVL_tree<int, int> MakeTree(int start_counter, int final_counter){
    /*
     * создаёт дерево
     */
    AVL_tree<int, int> TREE;
    for(int i = start_counter;i < final_counter; i++){
        TREE.InsertNode(i, i);
    }
    std::vector<int> array;
    for(int i = start_counter; i < final_counter; i++){
        array.push_back(i);
    }
    assert(TraverseTree(TREE) == array);
    return TREE;
}

AVL_tree<int, int> DeleteTree(int start_counter, int final_counter, AVL_tree<int, int> TREE){
    /*
     * удаляется все элементы дерева и лишние
     */
    for(int i = start_counter - 5; i < final_counter + 5; i++){
        TREE.DeleteNode(i);
    }
    assert(TREE.begin() == TREE.end());
    return TREE;
}

void FindNode(int start_counter, int final_coutner, AVL_tree<int, int> TREE){
    /*
     * ищет каждый элемент
     */
    for(int i = start_counter; i < final_coutner; i++) {
        auto A = *TREE.FindNode(i);
        assert(A.first == i);
    }
}

void Tester(){
    /*
     * проводит тесты для всех вариций от -5 до 1000 элементов
     */
    AVL_tree<int, int> TREE;
    for(int i = START_COUNTER; i < FINAL_COUNTER; i++){
        TREE = MakeTree(i, FINAL_COUNTER);
        FindNode(i, FINAL_COUNTER, TREE);
        TREE = DeleteTree(i, FINAL_COUNTER, TREE);
    }
}


void TestFindNodeHand(){
    /*
    * тест на поиск несуществуешего значения
    */
    AVL_tree<int, int> T = CreateTree();
    try {
        auto A = *T.FindNode(100);
    }
    catch(std::invalid_argument &error){

    }
    /*
    * тест на поиск в пустом дереве
    */
    AVL_tree<int, int> S = CreateTree();
    try {
        auto A = *S.FindNode(100);
    }
    catch(std::invalid_argument &error){

    }
}


void TestFindNodeRandom(){
    /*
     * поиск рандомным данных по дереву
     */
    AVL_tree<int, int> T = CreateTree();
    for(int i = 0; i < 100; i++){
        int rand_number = 0 + rand() % 99;
        auto A = *T.FindNode(rand_number);
        assert(A.first == rand_number);
    }
}

void TestInsertRandom(){
    /*
     * вставка рандомных элементов
     */
    AVL_tree<int, int> T;
    std::vector<int> array;
    for(int i = 0; i < 1000; i++) {
        int rand_number = 1 + rand() % 1000;
        T.InsertNode(rand_number, rand_number);
        array.push_back(rand_number);
    }
    std::sort(array.begin(), array.end());
    assert(TraverseTree(T) == array);
}

void TestDeleteRandom(){
    AVL_tree<int, int> T = CreateTree();
    std::vector<int> array;
    for(int i = 0; i < 1000; i++){
        array.push_back(i);
    }
    for(int i = 0; i < 500; i++){
        int rand_number = 1 + rand() % 1000;
        T.DeleteNode(rand_number);
        auto index = std::find(array.begin(), array.end(), rand_number);
        if(index != array.end())
            array.erase(index);
    }
    assert(TraverseTree(T) == array);
}


signed main(){
    TEST_CASE(Tester)
    TEST_CASE(TestFindNodeHand)
    TEST_CASE(TestFindNodeRandom)
    TEST_CASE(TestInsertRandom)
    TEST_CASE(TestDeleteRandom)
}