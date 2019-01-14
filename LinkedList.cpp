//
// Created by michael on 1/10/19.
//

#include "LinkedList.h"
#include <iomanip>

LinkedList::LinkedList() {
    this->head = nullptr;
    for (int i = 0; i < NUM_OF_TURNS; i++) {
        Add(00);
    }
}

LinkedList::~LinkedList() {
    Node *curr = this->head;
    while (curr != nullptr) {
        Node *prev = curr;
        curr = curr->next;
        delete prev;
    }
}

Node *LinkedList::Get(int position) {
    Node *curr = this->head;
    for (int i = 0; i < position; i++)
        curr = curr->next;
    return curr;
}

void LinkedList::Set(int position, int value) {
    Node *node = Get(position);
    node->data = value;
}

void LinkedList::Add(int value) {
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;
    if (this->head == nullptr) {
        newNode->direction = Right;
        this->head = newNode;
    } else {
        Node *currNode = this->head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        if (currNode->direction == Left)
            newNode->direction = Right;
        else
            newNode->direction = Left;
        currNode->next = newNode;
    }
}

std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    output;
    for (int i = 0; i < NUM_OF_TURNS; i++)
        output << ((list.Get(i)->direction == Left) ? "L" : "R") << std::setfill('0') << std::setw(2)
               << list.Get(i)->data << " ";

    return output;
}
