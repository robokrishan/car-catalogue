#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include "../car.h"

class LinkedList {
    private:
        struct Node {
            Car* pData;
            Node* pNext;
        };

        Node* pHead;

    public:
        LinkedList();
        LinkedList(const string& szFilename);
        ~LinkedList();
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
        void insertAtEnd(Car car);
        void deleteHead();
        void deleteTail();
        void displayCar(Car* car);
        void display();
        string trimCsvInput(const string& str);
};

#endif /* LINKED_LIST_H */