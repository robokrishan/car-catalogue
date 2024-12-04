#include "engine.h"


// helpers
static uint16_t s_parseToUint16(const std::string& input) {
    try {
        return (uint16_t)stoi(input);
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid torque format!" << std::endl;
        return -1;
    } catch (const std::out_of_range&) {
        std::cerr << "Torque out of range!" << std::endl;
        return -2;
    }
}


// constructors
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

Engine::Engine(std::string szNewName, 
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

Engine::Engine(std::string szNewName,
                std::string szNewPower,
                std::string szNewTorque,
                std::string szNewIntake,
                std::string szNewCapacity,
                std::string szNewCylinders,
                std::string szNewFuel)
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
void Engine::setName(const std::string& szNewName) {
    this->szName = szNewName;
}

std::string Engine::getName() const {
    return this->szName;
}


// power
void Engine::setPowerHp(uint16_t uwNewPower) {
    this->uwPowerHp = uwNewPower;
}

void Engine::setPowerHp(const std::string& szNewPower) {
    this->uwPowerHp = s_parseToUint16(szNewPower);
}

uint16_t Engine::getPowerHp() const {
    return this->uwPowerHp;
}


// torque
void Engine::setTorqueNm(uint16_t uwNewTorque) {
    this->uwTorqueNm = uwNewTorque;
}

void Engine::setTorqueNm(const std::string& szNewTorque) {
    this->uwTorqueNm = s_parseToUint16(szNewTorque);
}

uint16_t Engine::getTorqueNm() const {
    return this->uwTorqueNm;
}


// intake
void Engine::setIntake(Intake_t eIntake) {
    this->eIntake = eIntake;
}

void Engine::setIntake(const std::string& szIntake) {
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

std::string Engine::getIntakeString() const {
    switch(this->eIntake) {
        case TURBO:             return "Turbo Charger";
        case TWIN_TURBO:        return "Twin Turbo";
        case STOCK:             
        default:                return "Stock";
        case SUPERCHARGER:      return "Supercharger";
    }
}


// cubic capacity
void Engine::setCapacity(const std::string& newCapacity) {
    try {
        fCubicCapacity = stof(newCapacity);
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid capacity format!" << std::endl;
    } catch (const std::out_of_range&) {
        std::cerr << "Capacity out of range!" << std::endl;
    }
}

void Engine::setCapacity(float newCapacity) {
    fCubicCapacity = newCapacity;
}

float Engine::getCapacity() const {
    return fCubicCapacity;
}


// cylinders
void Engine::setCylinders(const std::string& newCylinders) {
    try {
        ubCylinders = (uint8_t)std::stoi(newCylinders.c_str());
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid number of cylinders format!" << std::endl;
    } catch (const std::out_of_range&) {
        std::cerr << "Number of cylinders out of range!" << std::endl;
    }
}

void Engine::setCylinders(uint8_t newCylinders) {
    ubCylinders = newCylinders;
}

uint8_t Engine::getCylinders() const {
    return this->ubCylinders;
}


// fuel
void Engine::setFuel(const std::string& newFuel) {
    if (newFuel == "Petrol") {
        this->eFuel = PETROL;
    } else if (newFuel == "Diesel") {
        this->eFuel = DIESEL;
    } else {
        this->eFuel = NONE;
    }
}

void Engine::setFuel(Fuel_t newFuel) {
    this->eFuel = newFuel;
    std::cout << "Set fuel to " << this->getFuelString() << std::endl;
}

std::string Engine::getFuelString() const {
    switch (this->eFuel) {
        case PETROL: return "Petrol";
        case DIESEL: return "Diesel";

        case NONE: return "Unknown";
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
