#include <iostream>
#include <fstream>
#include <sstream>
#include "linked_list.h"

using namespace std;

// #define DEBUG

// constructors / destructors
LinkedList::LinkedList() {

}

LinkedList::LinkedList(const string& szFilename) {
    ifstream database(szFilename);

    if(!database.is_open()) {
        cerr << "Error opening file: " << szFilename << endl;
        return;
    }

    if (database.peek() == 0xEF) {
        char bom[3];
        database.read(bom, 3); // Skip BOM
    }

    *this = LinkedList();

    string line;
    bool isHeader = true;
    while(getline(database, line)) {
        if (line.empty()) {
            continue;
        }

        istringstream ss(line);

        if(isHeader) {
            isHeader = false;

            string label_brand, label_model, label_segment, label_body, 
                    label_yearRange, label_capacity, label_cylinders, 
                    label_fuel;
        
            // Read each column, trim, and print
            getline(ss, label_brand, ',');
            getline(ss, label_model, ',');
            getline(ss, label_segment, ',');
            getline(ss, label_body, ',');
            getline(ss, label_yearRange, ',');
            getline(ss, label_capacity, ',');
            getline(ss, label_cylinders, ',');
            getline(ss, label_fuel, ',');

            // Trim any extra spaces
            label_brand = this->trimCsvInput(label_brand);
            label_model = this->trimCsvInput(label_model);
            label_segment = this->trimCsvInput(label_segment);
            label_body = this->trimCsvInput(label_body);
            label_yearRange = this->trimCsvInput(label_yearRange);
            label_capacity = this->trimCsvInput(label_capacity);
            label_cylinders = this->trimCsvInput(label_cylinders);
            label_fuel = this->trimCsvInput(label_fuel);

            cout << "Database contains ";
            cout << label_brand << ", " << label_model << ", " << label_segment << ", " 
                << label_body << ", " << label_yearRange << ", " << label_capacity << ", " 
                << label_cylinders << ", " << label_fuel << endl << endl << endl;
        }

        // Processing data rows
        string brand, model, segment, body, yearRange, capacity, cylinders, fuel;
        
        // Read each column, trim, and print
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, segment, ',');
        getline(ss, body, ',');
        getline(ss, yearRange, ',');
        getline(ss, capacity, ',');
        getline(ss, cylinders, ',');
        getline(ss, fuel, ',');

        // Trim any extra spaces
        brand = this->trimCsvInput(brand);
        model = this->trimCsvInput(model);
        segment = this->trimCsvInput(segment);
        body = this->trimCsvInput(body);
        yearRange = this->trimCsvInput(yearRange);
        capacity = this->trimCsvInput(capacity);
        cylinders = this->trimCsvInput(cylinders);
        fuel = this->trimCsvInput(fuel);

        // Check if all columns are correctly populated
        if (brand.empty() || model.empty() || segment.empty() || body.empty() || 
            yearRange.empty() || capacity.empty() || cylinders.empty() || fuel.empty()) {
#ifdef DEBUG
            cerr << "Warning: Empty field detected in row!" << endl;
#endif
            continue; // Skip rows with empty fields
        }
#ifdef DEBUG
        // Print the row data for debugging
        cout << brand << ", " << model << ", " << segment << ", " 
            << body << ", " << yearRange << ", " << capacity << ", " 
            << cylinders << ", " << fuel << endl;
#endif
        Car newCar(brand, model, segment, body, yearRange, capacity, cylinders, fuel);
        this->insertAtBeginning(newCar);
    }

    database.close();
}

LinkedList::~LinkedList() {
    Node* current = pHead;
    while (current != NULL) {
        Node* next = current->pNext;
        if (current->pData) {
            delete current->pData;  // Delete Car object
        }
        delete current;  // Delete Node
        current = next;
    }
    pHead = NULL;  // Avoid dangling head pointer

#ifdef DEBUG
    cout << "linked list destroyed." << endl;
#endif
}


// insert
void LinkedList::insertAtBeginning(const string& newBrand, 
                                    const string& newModel,
                                    const string& newSegment, 
                                    const string& newBody,
                                    uint16_t yearLow, 
                                    uint16_t yearHigh, 
                                    float newCapacity,
                                    uint8_t newCylinders, 
                                    Fuel_t newFuel) 
{
    Car* newCar = new Car(newBrand, newModel, newSegment, newBody, yearLow, yearHigh, newCapacity, newCylinders, newFuel);
    Node* newNode = new Node{newCar, pHead};
    pHead = newNode;
}

void LinkedList::insertAtBeginning(const Car& car) {
    Node* newNode = new Node();
    newNode->pData = new Car(car);

    newNode->pNext = pHead;
    pHead = newNode;
}

void LinkedList::insertAtEnd(const string& newBrand, 
                                const string& newModel,
                                const string& newSegment, 
                                const string& newBody,
                                uint16_t yearLow, 
                                uint16_t yearHigh, 
                                float newCapacity,
                                uint8_t newCylinders, 
                                Fuel_t newFuel) 
{
    Car* newCar = new Car(newBrand, newModel, newSegment, newBody, yearLow, yearHigh, newCapacity, newCylinders, newFuel);
    Node* newNode = new Node{newCar, NULL};
    if (!pHead) {
        pHead = newNode;
    } else {
        Node* temp = pHead;
        while (temp->pNext) {
            temp = temp->pNext;
        }
        temp->pNext = newNode;
    }
}

void LinkedList::insertAtEnd(Car car) {
    Node* newCar = new Node();
    Car* newCarPtr = new Car(car);  // Dynamically allocate memory for the car object
    newCar->pData = newCarPtr;
    newCar->pNext = NULL;

    if (!pHead) {
        pHead = newCar;
        return;
    }

    Node* pTemp = pHead;
    while (pTemp->pNext) {
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = newCar;
}


// delete
void LinkedList::deleteHead() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;
    pHead = pHead->pNext;
    delete pTemp;
}

void LinkedList::deleteTail() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    if(!pHead->pNext) {
        delete pHead;
        pHead = NULL;
        return;
    }

    Node* pTemp = pHead;

    while(pTemp->pNext->pNext) {
        pTemp = pTemp->pNext;
    }

    delete pTemp->pNext;

    pTemp->pNext = NULL;
}


// display
void LinkedList::displayCar(Car* car) {
    cout << "                          |" << endl;
    cout << "|-------------------------------------------------|\n";

    printf("\tBrand:\t\t%s\n", car->getBrand().c_str());
    printf("\tModel:\t\t%s\n", car->getModel().c_str());
    printf("\tSegment:\t%s\n", car->getSegment().c_str());
    printf("\tBody:\t\t%s\n", car->getBody().c_str());
    printf("\tYears:\t\t%d - %d\n", car->getYearLow(), car->getYearHigh());
    printf("\tCapacity:\t%0.1f L\n", car->getCapacity());
    printf("\tCylinders:\t%d\n", car->getCylinders());
    printf("\tFuel:\t\t%s\n", car->getFuelString().c_str());

    cout << "|-------------------------------------------------|\n";
    cout << "                          |" << endl;
}

void LinkedList::display() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;
    while(pTemp) {
        displayCar(pTemp->pData);
        pTemp = pTemp->pNext;
    }

    cout << "                          |" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          NULL" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          |" << endl;
}


// data processing
string LinkedList::trimCsvInput(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return ""; // No non-space character
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}