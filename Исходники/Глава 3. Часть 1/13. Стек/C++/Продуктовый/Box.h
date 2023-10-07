#ifndef BOX_H
#define BOX_H

#include <iostream>


struct Box {
	int data;
	Box* next;
	Box(int new_data, Box* new_next); //Node
};

#endif /*BOX_H*/