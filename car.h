#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

enum Fuel_t {
    NONE = -1,
    PETROL = 0,
    DIESEL = 1,
};

class Car {
    private:
        static const string fuelPetrol;
        static const string fuelDiesel;

        string szBrand;
        string szModel;
        string szSegment;
        string szBody;
        uint16_t uwYearLow, uwYearHigh;
        float fCubicCapacity;
        uint8_t ubCylinders;
        Fuel_t eFuel;
        
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
            float newCapacity,
            uint8_t newCylinders,
            Fuel_t newFuel);
        Car(string newBrand,
            string newModel,
            string newSegment,
            string newBody,
            string yearRange,
            string newCapacity,
            string newCylinders,
            string newFuel);
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

        void setCapacity(const string& newCapacity);
        void setCapacity(float newCapacity);
        float getCapacity(void) const;

        void setCylinders(const string& newCylinders);
        void setCylinders(uint8_t newCylinders);
        uint8_t getCylinders(void) const;

        void setFuel(const string& newFuel);
        void setFuel(Fuel_t newFuel);
        string getFuelString(void) const;
        Fuel_t getFuel(void) const;
};

#endif /* CAR_H */