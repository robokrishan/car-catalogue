#ifndef DATABASE_PARSER_H
#define DATABASE_PARSER_H

#include <iostream>
#include <string>
#include "car/car.h"

class DatabaseParser {
    private:
        std::string szFilename;
        std::vector<Car> vCars;

        std::unordered_map<std::string, std::vector<int>> umBrands;
        std::unordered_map<std::string, std::vector<int>> umModels;
        std::unordered_map<std::string, std::vector<int>> umSegments;
        std::unordered_map<std::string, std::vector<int>> umBodies;
        std::unordered_map<uint16_t, std::vector<int>> umYearLows;
        std::unordered_map<uint16_t, std::vector<int>> umYearHighs;
        std::unordered_map<std::string, std::vector<int>> umEngines;
        std::unordered_map<uint16_t, std::vector<int>> umPowers;
        std::unordered_map<uint16_t, std::vector<int>> umTorques;
        std::unordered_map<std::string, std::vector<int>> umIntakes;
        std::unordered_map<float, std::vector<int>> umCapacities;
        std::unordered_map<uint8_t, std::vector<int>> umCylinders;
        std::unordered_map<std::string, std::vector<int>> umFuels;

        bool buildIndexes(void);
        bool loadFromFile(void);
        std::string trimCsvInput(const string& szString);

    public:
        DatabaseParser();
        DatabaseParser(const std::string& filename);
        ~DatabaseParser();

        void setFilename(const std::string& filename);
        std::string getFilename(void) const;
        
        const std::vector<Car>& getDatabase(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getBrands(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getModels(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getSegments(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getBodies(void) const;
        const std::unordered_map<uint16_t, std::vector<int>>& getYearLows(void) const;
        const std::unordered_map<uint16_t, std::vector<int>>& getYearHighs(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getEngines(void) const;
        const std::unordered_map<uint16_t, std::vector<int>>& getPowers(void) const;
        const std::unordered_map<uint16_t, std::vector<int>>& getTorques(void) const;
        const std::unordered_map<std::string, std::vector<int>>& getIntakes(void) const;
        const std::unordered_map<float, std::vector<int>>& getCapacities(void) const;
        const std::unordered_map<uint8_t, std::vector<int>>& getCylinders(void) const;
        const std::unordered_map<std::string, std::vector<int>> getFuels(void) const;
        
        std::vector<Car> filterByBrand(const std::string& brand) const;

        void displayAll(void) const;
};

#endif /* DATABASE_PARSER_H */