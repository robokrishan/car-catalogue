#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "../car/car.h"
#include "../linked_list/linked_list.h"
#include "../doubly_linked_list/doubly_linked_list.h"

class Parser {
    private:
        std::string szFilename;
        LinkedList* pHeaders;
        DoublyLinkedList* pObjects;
        uint8_t ubDimensions;
        uint16_t uwObjectCount;
        
    public:
        Parser();
        Parser(const std::string& szNewFilename);
        ~Parser();

        void setFilename(const std::string& szNewFilename);
        std::string getFilename(void) const;
        void extractHeaders(const std::string& szHeaders);
        std::string trimCsvInput(const string& szString);
        
        Car* parseCar(string szBrand, string szModel, string szSegment,
                        string szBody, string szYear, string szEngine,
                        string szPower, string szTorque, string szIntake,
                        string szCapacity, string szCylinders, string szFuel);

        void display(void) const;
};

#endif /* PARSER_H */