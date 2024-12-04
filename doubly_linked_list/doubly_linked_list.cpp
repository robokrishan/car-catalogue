#include <iostream>
#include <fstream>
#include <sstream>
#include "doubly_linked_list.h"

using namespace std;

// #define DEBUG

// constructors / destructors
DoublyLinkedList::DoublyLinkedList() {

}

DoublyLinkedList::~DoublyLinkedList() {
    Node* pCurrent = pHead;
    while(pCurrent != NULL) {
        Node* pNext = pCurrent->pNext;
        if(pCurrent->pData) {
            delete pCurrent->pData;
        }

        delete pCurrent;
        pCurrent = pNext;
    }

    pHead = NULL;

#ifdef DEBUG
    cout << "doubly linked list destroyed." << endl;
#endif
}


// insert
void DoublyLinkedList::insertAtBeginning(const Car& car) {
    Node* newNode = new Node();

    newNode->pData = new Car(car);
    newNode->pNext = pHead;

    if (NULL != pHead) {
        pHead->pPrev = newNode;
    }

    pHead = newNode;

    if(NULL == pTail) {
        pTail = newNode;
    }
}

void DoublyLinkedList::insertAtEnd(const Car& car) {
    Node* newNode = new Node();
    newNode->pData = new Car(car);

    if(!pTail) {
        pTail = newNode;
        pHead = newNode;
    } else {
        newNode->pPrev = pTail;
        pTail->pNext = newNode;
        pTail = newNode;
    }
}


// delete
void DoublyLinkedList::deleteHead() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;

    if(pHead == pTail) {
        pHead = NULL;
        pTail = NULL;
    } else {
        pHead = pHead->pNext;
        pHead->pPrev = NULL;
    }

    delete pTemp;
}

void DoublyLinkedList::deleteTail() {
    if(!pTail) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pTail;

    if(pTail == pHead) {
        pHead = NULL;
        pTail = NULL;
    } else {
        pTail = pTail->pPrev;
        pTail->pNext = NULL;
    }

    delete pTemp;
}


// display
void DoublyLinkedList::display() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;
    while(pTemp) {
        pTemp->pData->display();
        pTemp = pTemp->pNext;
    }

    cout << "                          |" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          NULL" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          |" << endl;
}
