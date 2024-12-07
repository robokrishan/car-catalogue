#include "database_parser.h"
#include <fstream>
#include <sstream>

DatabaseParser::DatabaseParser() {
    this->setFilename("");
}

DatabaseParser::DatabaseParser(const std::string& filename) {
    this->setFilename(filename);
    this->loadFromFile();
    this->buildIndexes();
}

DatabaseParser::~DatabaseParser() {

}

void DatabaseParser::setFilename(const std::string& filename) {
    this->szFilename = filename;    
}

std::string DatabaseParser::getFilename(void) const {
    return this->szFilename;
}

const std::vector<Car>& DatabaseParser::getDatabase(void) const {
    return this->vCars;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getBrands(void) const {
    return this->umBrands;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getModels(void) const {
    return this->umModels;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getSegments(void) const {
    return this->umSegments;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getBodies(void) const {
    return this->umBodies;
}

const std::unordered_map<uint16_t, std::vector<int>>& DatabaseParser::getYearLows(void) const {
    return this->umYearLows;
}

const std::unordered_map<uint16_t, std::vector<int>>& DatabaseParser::getYearHighs(void) const {
    return this->umYearHighs;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getEngines(void) const {
    return this->umEngines;
}

const std::unordered_map<uint16_t, std::vector<int>>& DatabaseParser::getPowers(void) const {
    return this->umPowers;
}

const std::unordered_map<uint16_t, std::vector<int>>& DatabaseParser::getTorques(void) const {
    return this->umTorques;
}

const std::unordered_map<std::string, std::vector<int>>& DatabaseParser::getIntakes(void) const {
    return this->umIntakes;
}

const std::unordered_map<float, std::vector<int>>& DatabaseParser::getCapacities(void) const {
    return this->umCapacities;
}

const std::unordered_map<uint8_t, std::vector<int>>& DatabaseParser::getCylinders(void) const {
    return this->umCylinders;
}

const std::unordered_map<std::string, std::vector<int>> DatabaseParser::getFuels(void) const {
    return this->umFuels;
}

bool DatabaseParser::loadFromFile(void) {
    ifstream database(this->szFilename);
    if(!database.is_open()) {
        std::cerr << "Error opening file: " << this->szFilename << std::endl;
        return 0;
    }

    // Skip BOM bits
    if(database.peek() == 0xEF) {
        char bom[3];
        database.read(bom, 3);
    }

    string szDataBuffer, szHeaderBuffer;

    // read headers into buffer, empty line check
    getline(database, szHeaderBuffer);
    while(szHeaderBuffer.empty()) {
        getline(database, szHeaderBuffer);
    }

    while(getline(database, szDataBuffer)) {
        string szBrand, szModel, szSegment, szBody,
                szYear, szEngine, szPower, szTorque,
                szIntake, szCapacity, szCylinder, szFuel;

        istringstream ss(szDataBuffer);

        getline(ss, szBrand, ',');
        getline(ss, szModel, ',');
        getline(ss, szSegment, ',');
        getline(ss, szBody, ',');
        getline(ss, szYear, ',');
        getline(ss, szEngine, ',');
        getline(ss, szPower, ',');
        getline(ss, szTorque, ',');
        getline(ss, szIntake, ',');
        getline(ss, szCapacity, ',');
        getline(ss, szCylinder, ',');
        getline(ss, szFuel, ',');

        szBrand = this->trimCsvInput(szBrand);
        szModel = this->trimCsvInput(szModel);
        szSegment = this->trimCsvInput(szSegment);
        szBody = this->trimCsvInput(szBody);
        szYear = this->trimCsvInput(szYear);
        szEngine = this->trimCsvInput(szEngine);
        szPower = this->trimCsvInput(szPower);
        szTorque = this->trimCsvInput(szTorque);
        szIntake = this->trimCsvInput(szIntake);
        szCapacity = this->trimCsvInput(szCapacity);
        szCylinder = this->trimCsvInput(szCylinder);
        szFuel = this->trimCsvInput(szFuel);

        this->vCars.push_back(Car(szBrand,
                                    szModel,
                                    szSegment,
                                    szBody,
                                    szYear,
                                    Engine(szEngine,
                                            szPower,
                                            szTorque,
                                            szIntake,
                                            szCapacity,
                                            szCylinder,
                                            szFuel)));
    }

    database.close();
    
    return 1;
}

bool DatabaseParser::buildIndexes(void) {
    if(vCars.size() < 1) {
        return 0;
    }

    for (int i = 0; i < vCars.size(); i++) {
        const Car& car = vCars[i];

        this->umBrands[car.getBrand()].push_back(i);
        this->umModels[car.getModel()].push_back(i);
        this->umSegments[car.getSegment()].push_back(i);
        this->umBodies[car.getBody()].push_back(i);
        this->umYearLows[car.getYearLow()].push_back(i);
        this->umYearHighs[car.getYearHigh()].push_back(i);
        this->umEngines[car.getEngine().getName()].push_back(i);
        this->umPowers[car.getEngine().getPowerHp()].push_back(i);
        this->umTorques[car.getEngine().getTorqueNm()].push_back(i);
        this->umIntakes[car.getEngine().getIntakeString()].push_back(i);
        this->umCapacities[car.getEngine().getCapacity()].push_back(i);
        this->umCylinders[car.getEngine().getCylinders()].push_back(i);
        this->umFuels[car.getEngine().getFuelString()].push_back(i);
    }

    return 1;
}

std::string DatabaseParser::trimCsvInput(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return ""; // No non-space character
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}