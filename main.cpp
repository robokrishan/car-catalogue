#include <iostream>
#include <string>
#include "parser.h"

// #include "doubly_linked_list/doubly_linked_list.h"

using namespace std;

int main() {
    string szFilename = "Car_Shopping_Wishlist.csv";
    
    // DoublyLinkedList sDll = DoublyLinkedList(szFilename);
    // sDll.display();

    Parser database(szFilename);
    database.display();

    cout << endl << endl << endl;

    return 0;
}
