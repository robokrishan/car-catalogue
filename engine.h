#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>


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
        std::string szName;
        uint16_t uwPowerHp;
        uint16_t uwTorqueNm;
        Intake_t eIntake;
        float fCubicCapacity;
        uint8_t ubCylinders;
        Fuel_t eFuel;

    public:
        Engine();
        Engine(const Engine& engine);
        Engine(std::string szNewName, 
                uint16_t uwNewPower, 
                uint16_t uwNewTorque, 
                Intake_t eNewIntake, 
                float fNewCapacity, 
                uint8_t ubNewCylinders, 
                Fuel_t eNewFuel);
        Engine(std::string szNewName,
                std::string szNewPower,
                std::string szNewTorque,
                std::string szNewIntake,
                std::string szNewCapacity,
                std::string szNewCylinders,
                std::string szNewFuel);
        ~Engine();

        void setName(const std::string& szNewName);
        std::string getName(void) const;

        void setPowerHp(uint16_t uwNewPower);
        void setPowerHp(const std::string& szNewPower);
        uint16_t getPowerHp(void) const;

        void setTorqueNm(uint16_t uwNewTorque);
        void setTorqueNm(const std::string& szNewTorque);
        uint16_t getTorqueNm(void) const;

        void setIntake(Intake_t eIntake);
        void setIntake(const std::string& szIntake);
        Intake_t getIntake(void) const;
        std::string getIntakeString(void) const;

        void setCapacity(const std::string& newCapacity);
        void setCapacity(float newCapacity);
        float getCapacity(void) const;

        void setCylinders(const std::string& newCylinders);
        void setCylinders(uint8_t newCylinders);
        uint8_t getCylinders(void) const;

        void setFuel(const std::string& newFuel);
        void setFuel(Fuel_t newFuel);
        std::string getFuelString(void) const;
        Fuel_t getFuel(void) const;

        void display(void) const;
};

#endif /* ENGINE_H */