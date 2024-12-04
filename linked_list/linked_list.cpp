#include <iostream>
#include <fstream>
#include <sstream>
#include "linked_list.h"


// constructors / destructors
LinkedList::LinkedList() {
    this->pHead = NULL;
}

LinkedList::LinkedList(const std::string& szColumn) {
    this->pHead = new Node();
    this->pHead->szString = szColumn;
    this->pHead->pNext = NULL;
}

LinkedList::~LinkedList() {
    Node* current = pHead;
    while (current != NULL) {
        Node* next = current->pNext;
        delete current;  // Delete Node
        current = next;
    }
    pHead = NULL;  // Avoid dangling head pointer

#ifdef DEBUG
    cout << "linked list destroyed." << endl;
#endif
}


// insert
void LinkedList::insertAtBeginning(const std::string& szNewColumn) {
    Node* newNode = new Node();
    newNode->szString = szNewColumn;

    newNode->pNext = pHead;
    pHead = newNode;
}

void LinkedList::insertAtEnd(const std::string& szNewColumn) {
    Node* newNode = new Node(); // Dynamically allocate memory for the car object
    newNode->szString = szNewColumn;
    newNode->pNext = NULL;

    if (!pHead) {
        pHead = newNode;
        return;
    }

    Node* pTemp = pHead;
    while (pTemp->pNext) {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = newNode;
}


// delete
void LinkedList::deleteHead() {
    if(!pHead) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* pTemp = pHead;
    pHead = pHead->pNext;
    delete pTemp;
}

void LinkedList::deleteTail() {
    if(!pHead) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if(!pHead->pNext) {
        delete pHead;
        pHead = NULL;
        return;
    }

    Node* pTemp = pHead;

    while(pTemp->pNext->pNext) {
        pTemp = pTemp->pNext;
    }

    delete pTemp->pNext;

    pTemp->pNext = NULL;
}


// getter
Node* LinkedList::getHead(void) const {
    return this->pHead;
}
