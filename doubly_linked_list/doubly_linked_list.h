#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>
#include "../car.h"


class DoublyLinkedList {
    private:
        struct Node {
            Car* pData;
            Node* pNext;
            Node* pPrev;
        };

        Node* pHead;
        Node* pTail;

    public:
        DoublyLinkedList();
        DoublyLinkedList(const string& szFilename);
        ~DoublyLinkedList();

        void insertAtBeginning(const Car& car);
        void insertAtEnd(const Car& car);
        void deleteHead();
        void deleteTail();
        void display();
        string trimCsvInput(const string& str);
};

#endif /* DOUBLY_LINKED_LIST_H */