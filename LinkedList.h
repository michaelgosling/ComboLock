//
// Created by michael on 1/10/19.
//

#ifndef COMBOLOCK_LINKEDLIST_H
#define COMBOLOCK_LINKEDLIST_H

#include <iostream>

#define NUM_OF_TURNS 7

enum Direction {
    Left, Right
};

struct Node {
    Direction direction;
    int data;
    struct Node *next;
};

class LinkedList {
private:
    struct Node *head;

    void Add(int);

public:
    LinkedList();

    ~LinkedList();

    Node *Get(int position);

    void Set(int position, int value);

    friend std::ostream &operator<<(std::ostream &, LinkedList &);
};

#endif //COMBOLOCK_LINKEDLIST_H
