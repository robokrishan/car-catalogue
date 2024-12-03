#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include "engine.h"

using namespace std;

class Car {
    private:
        string szBrand;
        string szModel;
        string szSegment;
        string szBody;
        uint16_t uwYearLow, uwYearHigh;
        Engine sEngine;
        
    public:
        Car();
        Car(const Car& car);
        Car(string line_csv);
        Car(string newBrand,
            string newModel,
            string newSegment,
            string newBody,
            uint16_t yearLow,
            uint16_t yearHigh,
            Engine engine);
        Car(string newBrand, 
            string newModel, 
            string newSegment, 
            string newBody,
            string yearRange, 
            Engine engine);
        ~Car();

        void setBrand(const string& newBrand);
        string getBrand(void) const;

        void setModel(const string& newModel);
        string getModel(void) const;

        void setSegment(const string& newSegment);
        string getSegment(void) const;

        void setBody(const string& newBody);
        string getBody(void) const;

        void setYearRange(const string& newRange);
        void setYearRange(uint16_t newLow, uint16_t newHigh);
        
        uint16_t getYearLow(void) const;
        uint16_t getYearHigh(void) const;

        void setEngine(const Engine engine);
        Engine getEngine(void) const;

        void display(void) const;
};

#endif /* CAR_H */