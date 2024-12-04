#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

using namespace std;

enum Intake_t {
    STOCK = 0,
    TURBO = 1,
    TWIN_TURBO = 2,
    SUPERCHARGER = 3,
};

enum Fuel_t {
    NONE = -1,
    PETROL = 0,
    DIESEL = 1,
};

class Engine {
    private:
        string szName;
        uint16_t uwPowerHp;
        uint16_t uwTorqueNm;
        Intake_t eIntake;
        float fCubicCapacity;
        uint8_t ubCylinders;
        Fuel_t eFuel;

    public:
        Engine();
        Engine(const Engine& engine);
        Engine(string szNewName, 
                uint16_t uwNewPower, 
                uint16_t uwNewTorque, 
                Intake_t eNewIntake, 
                float fNewCapacity, 
                uint8_t ubNewCylinders, 
                Fuel_t eNewFuel);
        Engine(string szNewName,
                string szNewPower,
                string szNewTorque,
                string szNewIntake,
                string szNewCapacity,
                string szNewCylinders,
                string szNewFuel);
        ~Engine();

        void setName(const string& szNewName);
        string getName(void) const;

        void setPowerHp(uint16_t uwNewPower);
        void setPowerHp(const string& szNewPower);
        uint16_t getPowerHp(void) const;

        void setTorqueNm(uint16_t uwNewTorque);
        void setTorqueNm(const string& szNewTorque);
        uint16_t getTorqueNm(void) const;

        void setIntake(Intake_t eIntake);
        void setIntake(const string& szIntake);
        Intake_t getIntake(void) const;
        string getIntakeString(void) const;

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

        void display(void) const;
};

#endif /* ENGINE_H */