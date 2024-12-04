#include <iostream>
#include <string>

#include "doubly_linked_list/doubly_linked_list.h"

using namespace std;

int main() {
    string szFilename = "Car_Shopping_Wishlist.csv";
    
    DoublyLinkedList sDll = DoublyLinkedList(szFilename);
    sDll.display();
    cout << endl << endl << endl;

    return 0;
}
