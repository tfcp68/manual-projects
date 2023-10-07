#include "C_list.h"
using namespace std;

int main() {
    int x = 999;

    vector<int> vec = {1, 2, 3};


    LIST<int> l;

    l.push_back(1);
    l.push_back(5);
    l.push_back(10);
    l.push_back(15);
    l.push_back(20);
    l.push_back(25);
    l.push_back(30);
    l.push_back(35);
    l.push_back(40);
    auto it = l.begin();
    it+2;
    auto it2 = l.begin();
    it2+6;
    l.erase(it, it2);

    l = vec;
    return 0;
}