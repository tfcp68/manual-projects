#include "dll.h"

using namespace std;

int main() {
    DoublyLinkedList<int> dll;
    dll.pushBack(10);
    dll.pushFront(20);
    dll.pushBack(30);
    dll.pushFront(40);

    // Лист: 40 20 10 30

    dll.insert(60, 3);

    // Лист: 40 20 10 60 40

    dll.popFront();

    // Лист: 20 10 60 40

    return 0;
}