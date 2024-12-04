#include <sstream>
#include "car.h"

using namespace std;


// constructors
Car::Car() {
    setBrand("");
    setModel("");
    setSegment("");
    setBody("");
    setYearRange(-1, -1);
    setEngine(Engine());
}

Car::Car(const Car& car) : szBrand(car.szBrand), 
                            szModel(car.szModel),
                            szSegment(car.szSegment), 
                            szBody(car.szBody),
                            uwYearLow(car.uwYearLow), 
                            uwYearHigh(car.uwYearHigh),
                            sEngine(car.sEngine)
                            {}

Car::Car(string newBrand, 
            string newModel, 
            string newSegment, 
            string newBody,
            uint16_t yearLow, 
            uint16_t yearHigh,
            Engine engine) {
    setBrand(newBrand);
    setModel(newModel);
    setSegment(newSegment);
    setBody(newBody);
    setYearRange(yearLow, yearHigh);
    setEngine(engine);
}

Car::Car(string newBrand, 
            string newModel, 
            string newSegment, 
            string newBody,
            string yearRange, 
            Engine engine) {
    setBrand(newBrand);
    setModel(newModel);
    setSegment(newSegment);
    setBody(newBody);
    setYearRange(yearRange);
    setEngine(engine);
}


// destructors
Car::~Car() {}


// brand
void Car::setBrand(const string& newBrand) {
    szBrand = newBrand;
}

string Car::getBrand() const {
    return szBrand;
}


// model
void Car::setModel(const string& newModel) {
    szModel = newModel;
}

string Car::getModel() const {
    return szModel;
}


// segment
void Car::setSegment(const string& newSegment) {
    szSegment = newSegment;
}

string Car::getSegment() const {
    return szSegment;
}


// body
void Car::setBody(const string& newBody) {
    szBody = newBody;
}

string Car::getBody() const {
    return szBody;
}


// year
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


// engine
void Car::setEngine(const Engine engine) {
    this->sEngine.setName(engine.getName());
    this->sEngine.setPowerHp(engine.getPowerHp());
    this->sEngine.setTorqueNm(engine.getTorqueNm());
    this->sEngine.setIntake(engine.getIntake());
    this->sEngine.setCapacity(engine.getCapacity());
    this->sEngine.setCylinders(engine.getCylinders());
    this->sEngine.setFuel(engine.getFuel());
}

Engine Car::getEngine() const {
    return this->sEngine;
}


// display
void Car::display() const {
    cout << "                          |" << endl;
    cout << "|-------------------------------------------------|\n";

    printf("\tBrand:\t\t%s\n", this->getBrand().c_str());
    printf("\tModel:\t\t%s\n", this->getModel().c_str());
    printf("\tSegment:\t%s\n", this->getSegment().c_str());
    printf("\tBody:\t\t%s\n", this->getBody().c_str());
    printf("\tYears:\t\t%d - %d\n", this->getYearLow(), this->getYearHigh());

    this->sEngine.display();

    cout << "|-------------------------------------------------|\n";
    cout << "                          |" << endl;
}
