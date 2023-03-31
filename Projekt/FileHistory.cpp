#include <iostream>
#include <iomanip>
#include "Database.h"
#include "FileHistory.h"


void printHistoryHead() {
    std::cout
            << "------------------------------------------------------------------------------------------------------------"
            << std::endl;
    std::cout
            << "|     # | Date        | Id          | Dania                            | Cena   | N | C * N   | Suma       |"
            << std::endl;
    std::cout
            << "------------------------------------------------------------------------------------------------------------"
            << std::endl;
}

void printHistoryBody(int orderindex, int dishindex, bool top, Order order) // Если top == true то принтит дату и айди;
{
    std::string NAME = order.dishes[dishindex].getName();
    double PRICE = order.dishes[dishindex].getPrice();
    int AMOUNT = order.dishes[dishindex].getAmount();
    double TOTAL_PRICE = AMOUNT * PRICE;

    if (top) {
        // Numer
        std::cout << "|    ";
        if (orderindex < 10) { std::cout << 0; }
        std::cout << orderindex << " | ";

        // Date
        std::cout << order.getDate().getStringDate();

        // ID
        std::cout << "  | " << order.getID() << "  | ";
    } else {
        std::cout << "|       |             |             | ";
    }

    std::cout << NAME << std::string(33 - NAME.length(), ' ') << "| ";
    if (PRICE < 10) { std::cout << 0; }
    std::cout << fixed << setprecision(2) << PRICE << "  | " << AMOUNT << " | ";
    if (TOTAL_PRICE < 10) { std::cout << 0; }
    std::cout << fixed << setprecision(2) << TOTAL_PRICE << "   |          - |" << endl;
}

void printHistorySum(double suma) {
    std::cout << "|       |             |             |                                  |        |   |         |     ";
    if (suma < 10) { std::cout << ' '; }
    if (suma < 100) { std::cout << ' '; }
    std::cout << suma << " |" << std::endl;
    std::cout
            << "------------------------------------------------------------------------------------------------------------"
            << std::endl;
}

void printHistoryTotalSum(double suma) {
    std::cout << "|                                                                                            Suma: ";
    if (suma < 10) { std::cout << ' '; }
    if (suma < 100) { std::cout << ' '; }
    if (suma < 1000) { std::cout << ' '; }
    std::cout << suma << " | " << std::endl;
    std::cout
            << "------------------------------------------------------------------------------------------------------------"
            << std::endl;
}