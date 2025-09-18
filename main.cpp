#include <iostream>

#include "LinkedList.h"

int main() {

    // makes a linked list full of integers
    LinkedList<int> list;
    list.push_front(3); // adds element to the head of the linked list
    list.push_back(4); // adds elements to the tail of the linked lists
    list.push_back(5);
    list.push_back(6);

    list.print(); // prints linked list

    list.pop_front(); // removes the element at the head of the linked list.

    std::cout << "Updated Linked List: " << std::endl;

    list.print();
}