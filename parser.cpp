#include "parser.h"
#include <sstream>
#include <fstream>
#include "linked_list/linked_list.h"

Parser::Parser() {
    this->szFilename = "";
    pHeaders = new LinkedList();
    pObjects = new DoublyLinkedList();
    ubDimensions = 0;
    uwObjectCount = 0;
}

Parser::Parser(const std::string& szNewFilename) {
    *this = Parser();
    // set filename
    this->setFilename(szNewFilename);

    // open file
    ifstream database(this->getFilename());
    if(!database.is_open()) {
        cerr << "Error opening file: " << szFilename << endl;
        return;
    }

    // extract BOM chars
    if (database.peek() == 0xEF) {
        char bom[3];
        database.read(bom, 3); // Skip BOM
    }

    string szDataBuffer, szHeaderBuffer;
    
    // extract first non-empty line
    getline(database, szHeaderBuffer);
    while(szHeaderBuffer.empty()) {
        getline(database, szHeaderBuffer);
    }
    this->extractHeaders(szHeaderBuffer);

    // extract objects
    while(getline(database, szDataBuffer)) {
        string szBrand, szModel, szSegment, 
                szBody, szYear, szEngine, szPower,
                szTorque, szIntake, szCapacity,
                szCylinder, szFuel;
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

        pObjects->insertAtBeginning(Car(szBrand,
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
}

Parser::~Parser() {

}

void Parser::setFilename(const std::string& szNewFilename) {
    this->szFilename = szNewFilename;
}

std::string Parser::getFilename(void) const {
    return this->szFilename;
}

void Parser::extractHeaders(const std::string& szHeaderBuffer) {
    istringstream ss(szHeaderBuffer);
    string szColumn;
    
    while(getline(ss, szColumn, ',')) {
        pHeaders->insertAtBeginning(szColumn);
        szColumn.clear();
        this->ubDimensions++;
    }

    cout << "Found " << this->ubDimensions << " columns in database:" << endl;
    Node* pTemp = pHeaders->getHead();
    while(pTemp) {
        cout << pTemp->szString << endl;
        pTemp = pTemp->pNext;
    }
}

std::string Parser::trimCsvInput(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return ""; // No non-space character
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

void Parser::display(void) const {
    this->pObjects->display();
}