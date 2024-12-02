#include <iostream>
#include <string>

// #define LINKED_LIST
// #define DOUBLY_LINKED_LIST

#ifdef LINKED_LIST
#include "linked_list/linked_list.h"
#endif

#ifdef DOUBLY_LINKED_LIST
#include "doubly_linked_list/doubly_linked_list.h"
#endif

using namespace std;

int main() {
    string szFilename = "Car_Shopping_Wishlist.csv";

#ifdef LINKED_LIST
    LinkedList sList = LinkedList(szFilename);
    sList.display();
#endif

#ifdef DOUBLY_LINKED_LIST
    DoublyLinkedList sDll = DoublyLinkedList(szFilename);
    sDll.display();
#endif

    return 0;
}
