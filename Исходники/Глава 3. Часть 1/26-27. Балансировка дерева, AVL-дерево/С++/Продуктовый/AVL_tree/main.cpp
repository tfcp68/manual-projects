#include <iostream>
#include <map>
#include "AVL_tree.h"
#include "Tests.cpp"

/*
 * make custom comparator
 * return pair<key, data>
 * const iterator (cbegin, cend)
 * reverse iterator (#include <iterator> std::reverse_iterator<Iterator>)
 * begin - end
cbegin - cend = const iter
rbegin - rend = reverse
crbegin - crend = const reverse
 глянуть реализацию map
 https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_tree.h ссылОчка

 */


int main() {

    std::cout << "Hello, World!" << std::endl;
    AVL_tree<int, int> T{};
    T.InsertNode(2, 3);
    T.InsertNode(6, 34);
    T.InsertNode(8, 1);
    T.InsertNode(0, 2);
    T.InsertNode(4, 4);
}