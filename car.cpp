#include <iostream>
#include <sstream>
#include "car.h"

using namespace std;


// constants
const string Car::fuelPetrol = "Petrol";
const string Car::fuelDiesel = "Diesel";


// constructors
Car::Car() {
    setBrand("");
    setModel("");
    setSegment("");
    setBody("");
    setYearRange(-1, -1);
    setCapacity(-1.0);
    setCylinders(-1);
    setFuel(NONE);
}

Car::Car(const Car& car) : szBrand(car.szBrand), szModel(car.szModel),
                            szSegment(car.szSegment), szBody(car.szBody),
                            uwYearLow(car.uwYearLow), uwYearHigh(car.uwYearHigh),
                            fCubicCapacity(car.fCubicCapacity),
                            ubCylinders(car.ubCylinders), eFuel(car.eFuel) {}

Car::Car(string line_csv) {
    istringstream ss(line_csv);

    string szBrand, szModel, szBody, szSegment, szYearRange;
    string szCubicCapacity, szCylinders, szFuel;

    if (getline(ss, szBrand, ',') && 
        getline(ss, szModel, ',') &&
        getline(ss, szSegment, ',') &&
        getline(ss, szBody, ',') &&
        getline(ss, szYearRange, ',') &&
        getline(ss, szCubicCapacity, ',') &&
        getline(ss, szCylinders, ',') &&
        getline(ss, szFuel, ',')) {
        *this = Car(szBrand, szModel, szSegment, szBody, 
                    szYearRange, szCubicCapacity, 
                    szCylinders, szFuel);
    } else {
        cerr << "Invalid input format!" << endl;
    }
}

Car::Car(string newBrand, string newModel, string newSegment, string newBody,
            uint16_t yearLow, uint16_t yearHigh,
            float newCapacity, uint8_t newCylinders, Fuel_t newFuel) {
    setBrand(newBrand);
    setModel(newModel);
    setSegment(newSegment);
    setBody(newBody);
    setYearRange(yearLow, yearHigh);
    setCapacity(newCapacity);
    setCylinders(newCylinders);
    setFuel(newFuel);
}

Car::Car(string newBrand, string newModel, string newSegment, string newBody,
            string yearRange, string newCapacity,
            string newCylinders, string newFuel) {
    setBrand(newBrand);
    setModel(newModel);
    setSegment(newSegment);
    setBody(newBody);
    setYearRange(yearRange);
    setCapacity(newCapacity);
    setCylinders(newCylinders);
    setFuel(newFuel);
}


// destructors
Car::~Car() {}

// setters and getters
void Car::setBrand(const string& newBrand) {
    szBrand = newBrand;
}

string Car::getBrand() const {
    return szBrand;
}

void Car::setModel(const string& newModel) {
    szModel = newModel;
}

string Car::getModel() const {
    return szModel;
}

void Car::setSegment(const string& newSegment) {
    szSegment = newSegment;
}

string Car::getSegment() const {
    return szSegment;
}

void Car::setBody(const string& newBody) {
    szBody = newBody;
}

string Car::getBody() const {
    return szBody;
}

void Car::setYearRange(const string& newRange) {
    istringstream iss(newRange);
    char delimiter;

    if (!(iss >> uwYearLow >> delimiter >> uwYearHigh) || delimiter != '-') {
        cerr << "Invalid input format for year range!" << endl;
        return;
    }

    if (uwYearLow < 2000 || uwYearHigh > 2025) {
        cerr << "Year range out of bounds!" << endl;
    }
}

void Car::setYearRange(uint16_t newLow, uint16_t newHigh) {
    if (2000 > newLow || 2025 < newHigh) {
        cerr << "Invalid input range!" << endl;
        return;
    }

    uwYearLow = newLow;
    uwYearHigh = newHigh;
}

uint16_t Car::getYearLow() const {
    return uwYearLow;
}

uint16_t Car::getYearHigh() const {
    return uwYearHigh;
}

void Car::setCapacity(const string& newCapacity) {
    try {
        fCubicCapacity = stof(newCapacity);
    } catch (const invalid_argument&) {
        cerr << "Invalid capacity format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Capacity out of range!" << endl;
    }
}

void Car::setCapacity(float newCapacity) {
    fCubicCapacity = newCapacity;
}

float Car::getCapacity() const {
    return fCubicCapacity;
}

void Car::setCylinders(const string& newCylinders) {
    try {
        ubCylinders = (uint8_t)stoi(newCylinders.c_str());
    } catch (const invalid_argument&) {
        cerr << "Invalid number of cylinders format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Number of cylinders out of range!" << endl;
    }
}

void Car::setCylinders(uint8_t newCylinders) {
    ubCylinders = newCylinders;
}

uint8_t Car::getCylinders() const {
    return this->ubCylinders;
}

void Car::setFuel(const string& newFuel) {
    if (newFuel == fuelPetrol) {
        this->eFuel = PETROL;
    } else if (newFuel == fuelDiesel) {
        this->eFuel = DIESEL;
    } else {
        this->eFuel = NONE;
    }
}

void Car::setFuel(Fuel_t newFuel) {
    this->eFuel = newFuel;
    cout << "Set fuel to " << this->getFuelString() << endl;
}

string Car::getFuelString() const {
    switch (this->eFuel) {
        case PETROL: return string("Petrol");
        case DIESEL: return string("Diesel");

        case NONE: return string("Unknown");
    }
}

Fuel_t Car::getFuel() const {
    return this->eFuel;
}

