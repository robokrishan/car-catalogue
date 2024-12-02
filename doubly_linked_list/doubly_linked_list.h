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

        void insertAtBeginning(const std::string& newBrand, 
                                const std::string& newModel,
                                const std::string& newSegment, 
                                const std::string& newBody,
                                uint16_t yearLow, 
                                uint16_t yearHigh, 
                                float newCapacity,
                                uint8_t newCylinders, 
                                Fuel_t newFuel);
        void insertAtBeginning(const Car& car);
        void insertAtEnd(const std::string& newBrand, 
                            const std::string& newModel,
                            const std::string& newSegment, 
                            const std::string& newBody,
                            uint16_t yearLow, 
                            uint16_t yearHigh, 
                            float newCapacity,
                            uint8_t newCylinders, 
                            Fuel_t newFuel);
        void insertAtEnd(const Car& car);
        void deleteHead();
        void deleteTail();
        void displayCar(Car* car);
        void display();
        string trimCsvInput(const string& str);
};

#endif /* DOUBLY_LINKED_LIST_H */