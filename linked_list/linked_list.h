#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

struct Node {
    std::string szString;
    Node* pNext;
};

class LinkedList {
    private:
        Node* pHead;

    public:
        LinkedList();
        LinkedList(const std::string& szColumn);
        ~LinkedList();
        void insertAtBeginning(const std::string& szNewColumn);
        void insertAtEnd(const std::string& szNewColumn);
        void deleteHead();
        void deleteTail();
        Node* getHead(void) const;
};

#endif /* LINKED_LIST_H */