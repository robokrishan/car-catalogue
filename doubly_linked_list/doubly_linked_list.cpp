#include <iostream>
#include <fstream>
#include <sstream>
#include "doubly_linked_list.h"

using namespace std;

// #define DEBUG

// constructors / destructors
DoublyLinkedList::DoublyLinkedList() {

}

DoublyLinkedList::DoublyLinkedList(const string& szFilename) {
    ifstream database(szFilename);

    if(!database.is_open()) {
        cerr << "Error opening file: " << szFilename << endl;
        return;
    }

    if (database.peek() == 0xEF) {
        char bom[3];
        database.read(bom, 3); // Skip BOM
    }

    *this = DoublyLinkedList();


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
                    label_fuel, label_engine, label_power, label_torque,
                    label_intake;
        
            // Read each column, trim, and print
            getline(ss, label_brand, ',');
            getline(ss, label_model, ',');
            getline(ss, label_segment, ',');
            getline(ss, label_body, ',');
            getline(ss, label_yearRange, ',');
            getline(ss, label_engine, ',');
            getline(ss, label_power, ',');
            getline(ss, label_torque, ',');
            getline(ss, label_intake, ',');
            getline(ss, label_capacity, ',');
            getline(ss, label_cylinders, ',');
            getline(ss, label_fuel, ',');

            // Trim any extra spaces
            label_brand = this->trimCsvInput(label_brand);
            label_model = this->trimCsvInput(label_model);
            label_segment = this->trimCsvInput(label_segment);
            label_body = this->trimCsvInput(label_body);
            label_yearRange = this->trimCsvInput(label_yearRange);
            label_engine = this->trimCsvInput(label_engine);
            label_power = this->trimCsvInput(label_power);
            label_torque = this->trimCsvInput(label_torque);
            label_intake = this->trimCsvInput(label_intake);
            label_capacity = this->trimCsvInput(label_capacity);
            label_cylinders = this->trimCsvInput(label_cylinders);
            label_fuel = this->trimCsvInput(label_fuel);

            cout << "Databaase contains ";
            cout << label_brand << ", " << label_model << ", " << label_segment << ", " 
                << label_body << ", " << label_yearRange << ", " << label_engine << ", " 
                << label_power << ", " << label_torque << ", " << label_intake << ", " 
                << label_capacity << ", " << label_cylinders << ", " << label_fuel 
                << endl << endl << endl;
        }

        // Processing data rows
        string brand, model, segment, body, yearRange, engine, power,
                torque, intake, capacity, cylinders, fuel;
        
        // Read each column, trim, and print
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, segment, ',');
        getline(ss, body, ',');
        getline(ss, yearRange, ',');
        getline(ss, engine, ',');
        getline(ss, power, ',');
        getline(ss, torque, ',');
        getline(ss, intake, ',');
        getline(ss, capacity, ',');
        getline(ss, cylinders, ',');
        getline(ss, fuel, ',');

        // Trim any extra spaces
        brand = this->trimCsvInput(brand);
        model = this->trimCsvInput(model);
        segment = this->trimCsvInput(segment);
        body = this->trimCsvInput(body);
        yearRange = this->trimCsvInput(yearRange);
        engine = this->trimCsvInput(engine);
        power = this->trimCsvInput(power);
        torque = this->trimCsvInput(torque);
        intake = this->trimCsvInput(intake);
        capacity = this->trimCsvInput(capacity);
        cylinders = this->trimCsvInput(cylinders);
        fuel = this->trimCsvInput(fuel);

        // Check if all columns are correctly populated
        if (brand.empty() || model.empty() || segment.empty() || body.empty() || 
            yearRange.empty() || capacity.empty() || cylinders.empty() || 
            fuel.empty() || engine.empty() || power.empty() || torque.empty() ||
            intake.empty()) {
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
        Car newCar(brand, 
                    model, 
                    segment, 
                    body, 
                    yearRange, 
                    Engine(engine,
                            power,
                            torque,
                            intake,
                            capacity,
                            cylinders,
                            fuel));

        this->insertAtBeginning(newCar);
    }

    database.close();
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* pCurrent = pHead;
    while(pCurrent != NULL) {
        Node* pNext = pCurrent->pNext;
        if(pCurrent->pData) {
            delete pCurrent->pData;
        }

        delete pCurrent;
        pCurrent = pNext;
    }

    pHead = NULL;

#ifdef DEBUG
    cout << "doubly linked list destroyed." << endl;
#endif
}


// insert
void DoublyLinkedList::insertAtBeginning(const Car& car) {
    Node* newNode = new Node();

    newNode->pData = new Car(car);
    newNode->pNext = pHead;

    if (NULL != pHead) {
        pHead->pPrev = newNode;
    }

    pHead = newNode;

    if(NULL == pTail) {
        pTail = newNode;
    }
}

void DoublyLinkedList::insertAtEnd(const Car& car) {
    Node* newNode = new Node();
    newNode->pData = new Car(car);

    if(!pTail) {
        pTail = newNode;
        pHead = newNode;
    } else {
        newNode->pPrev = pTail;
        pTail->pNext = newNode;
        pTail = newNode;
    }
}


// delete
void DoublyLinkedList::deleteHead() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;

    if(pHead == pTail) {
        pHead = NULL;
        pTail = NULL;
    } else {
        pHead = pHead->pNext;
        pHead->pPrev = NULL;
    }

    delete pTemp;
}

void DoublyLinkedList::deleteTail() {
    if(!pTail) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pTail;

    if(pTail == pHead) {
        pHead = NULL;
        pTail = NULL;
    } else {
        pTail = pTail->pPrev;
        pTail->pNext = NULL;
    }

    delete pTemp;
}


// display
void DoublyLinkedList::display() {
    if(!pHead) {
        cout << "List is empty." << endl;
        return;
    }

    Node* pTemp = pHead;
    while(pTemp) {
        pTemp->pData->display();
        pTemp = pTemp->pNext;
    }

    cout << "                          |" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          NULL" << endl;
    cout << "|-------------------------------------------------|\n";
    cout << "                          |" << endl;
}


// data processing
string DoublyLinkedList::trimCsvInput(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return ""; // No non-space character
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}