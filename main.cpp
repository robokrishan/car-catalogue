#include <iostream>
#include <string>
#include "parser/parser.h"


int main() {
    std::string szFilename = "Car_Shopping_Wishlist.csv";
    
    Parser database(szFilename);
    database.display();

    std::cout << std::endl << std::endl << std::endl;

    return 0;
}
