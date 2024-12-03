#include "engine.h"

using namespace std;

// constants
const string Engine::fuelPetrol = "Petrol";
const string Engine::fuelDiesel = "Diesel";


Engine::Engine() {
    setName("");
    setPowerHp(-1);
    setTorqueNm(-1);
    setIntake(STOCK);
    setCapacity(-1.0);
    setCylinders(-1);
    setFuel(NONE);
}

Engine::Engine(const Engine& engine) : szName(engine.szName), 
                                        uwPowerHp(engine.uwPowerHp),
                                        uwTorqueNm(engine.uwTorqueNm),
                                        eIntake(engine.eIntake),
                                        fCubicCapacity(engine.fCubicCapacity),
                                        ubCylinders(engine.ubCylinders), 
                                        eFuel(engine.eFuel) {}

Engine::Engine(string szNewName, 
                uint16_t uwNewPower, 
                uint16_t uwNewTorque, 
                Intake_t eNewIntake, 
                float fNewCapacity, 
                uint8_t ubNewCylinders, 
                Fuel_t eNewFuel) :
                szName(szNewName),
                uwPowerHp(uwNewPower),
                uwTorqueNm(uwNewTorque),
                eIntake(eNewIntake),
                fCubicCapacity(fNewCapacity),
                ubCylinders(ubNewCylinders),
                eFuel(eNewFuel) {}

Engine::Engine(string szNewName,
                string szNewPower,
                string szNewTorque,
                string szNewIntake,
                string szNewCapacity,
                string szNewCylinders,
                string szNewFuel)
{
    this->setName(szNewName);
    this->setPowerHp(szNewPower);
    this->setTorqueNm(szNewTorque);
    this->setIntake(szNewIntake);
    this->setCapacity(szNewCapacity);
    this->setCylinders(szNewCylinders);
    this->setFuel(szNewFuel);
}

Engine::~Engine() {}


// name
void Engine::setName(const string& szNewName) {
    this->szName = szNewName;
}

string Engine::getName() const {
    return this->szName;
}


// power
void Engine::setPowerHp(uint16_t uwNewPower) {
    this->uwPowerHp = uwNewPower;
}

void Engine::setPowerHp(const string& szNewPower) {
    try {
        this->uwPowerHp = (uint16_t)stoi(szNewPower);
    } catch (const invalid_argument&) {
        cerr << "Invalid horsepower format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Horsepower out of range!" << endl;
    }
}

uint16_t Engine::getPowerHp() const {
    return this->uwPowerHp;
}


// torque
void Engine::setTorqueNm(uint16_t uwNewTorque) {
    this->uwTorqueNm = uwNewTorque;
}

void Engine::setTorqueNm(const string& szNewTorque) {
    try {
        this->uwTorqueNm = (uint16_t)stoi(szNewTorque);
    } catch (const invalid_argument&) {
        cerr << "Invalid torque format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Torque out of range!" << endl;
    }
}

uint16_t Engine::getTorqueNm() const {
    return this->uwTorqueNm;
}


// intake
void Engine::setIntake(Intake_t eIntake) {
    this->eIntake = eIntake;
}

void Engine::setIntake(const string& szIntake) {
    if("turbo charger" == szIntake || 
        "turbocharger" == szIntake || 
        "Turbo charger" == szIntake ||
        "Turbo Charger" == szIntake ||
        "turbo" == szIntake || 
        "Turbo" == szIntake) {
        this->eIntake = TURBO;
    } else if("twin turbo" == szIntake || 
                "Twin turbo" == szIntake ||
                "Twin Turbo" == szIntake) {
        this->eIntake = TWIN_TURBO;
    } else if("supercharger" == szIntake || "Supercharger" == szIntake ||
                "Super Charger" == szIntake || "super charger" == szIntake ||
                "Super charger" == szIntake)
    {
        this->eIntake = SUPERCHARGER;
    } else {
        this->eIntake = STOCK;
    }
}

Intake_t Engine::getIntake() const {
    return this->eIntake;
}

string Engine::getIntakeString() const {
    switch(this->eIntake) {
        case TURBO:             return "Turbo Charger";
        case TWIN_TURBO:        return "Twin Turbo";
        case SUPERCHARGER:      return "Supercharger";
        case STOCK:             
        default:                return "Stock";
    }
}


// cubic capacity
void Engine::setCapacity(const string& newCapacity) {
    try {
        fCubicCapacity = stof(newCapacity);
    } catch (const invalid_argument&) {
        cerr << "Invalid capacity format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Capacity out of range!" << endl;
    }
}

void Engine::setCapacity(float newCapacity) {
    fCubicCapacity = newCapacity;
}

float Engine::getCapacity() const {
    return fCubicCapacity;
}


// cylinders
void Engine::setCylinders(const string& newCylinders) {
    try {
        ubCylinders = (uint8_t)stoi(newCylinders.c_str());
    } catch (const invalid_argument&) {
        cerr << "Invalid number of cylinders format!" << endl;
    } catch (const out_of_range&) {
        cerr << "Number of cylinders out of range!" << endl;
    }
}

void Engine::setCylinders(uint8_t newCylinders) {
    ubCylinders = newCylinders;
}

uint8_t Engine::getCylinders() const {
    return this->ubCylinders;
}


// fuel
void Engine::setFuel(const string& newFuel) {
    if (newFuel == fuelPetrol) {
        this->eFuel = PETROL;
    } else if (newFuel == fuelDiesel) {
        this->eFuel = DIESEL;
    } else {
        this->eFuel = NONE;
    }
}

void Engine::setFuel(Fuel_t newFuel) {
    this->eFuel = newFuel;
    cout << "Set fuel to " << this->getFuelString() << endl;
}

string Engine::getFuelString() const {
    switch (this->eFuel) {
        case PETROL: return string("Petrol");
        case DIESEL: return string("Diesel");

        case NONE: return string("Unknown");
    }
}

Fuel_t Engine::getFuel() const {
    return this->eFuel;
}


// display
void Engine::display() const {
    printf("\tEngine:\n");
    printf("\t\tName:\t\t%s\n", this->getName().c_str());
    printf("\t\tPower:\t\t%d hp\n", this->getPowerHp());
    printf("\t\tTorque:\t\t%d Nm\n", this->getTorqueNm());
    printf("\t\tIntake:\t\t%s\n", this->getIntakeString().c_str());
    printf("\t\tCapacity:\t%0.1f L\n", this->getCapacity());
    printf("\t\tCylinders:\t%d\n", this->getCylinders());
    printf("\t\tFuel:\t\t%s\n", this->getFuelString().c_str());
}
