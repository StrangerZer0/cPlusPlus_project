#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>
#include "Database.h"
#include "FileIOEngine.h"
#include "FileHistory.h"


void callMainMenu() {
    cout << "Opcje:" << endl;
    cout << "[0] Zamknij program" << endl;
    cout << "[1] Złóż zamówienie" << endl;
    cout << "[2] Historia zamówień" << endl;
    cout << "[3] Historia zamówień dla danego dnia" << endl;
    cout << endl;
}

void printItem(Dish dish) {
    cout << "|  " << dish.getMenuID() << ". " << dish.getName()
         << string(30 - dish.getName().length() - dish.getMenuID() / 10, '.');
    if (dish.getPrice() < 10) { cout << 0; }
    cout << fixed << setprecision(2) << dish.getPrice() << "  |" << endl;
}

void printMenu(Menu menu) {

    cout << "------------------- MENU -------------------" << endl;
    cout << "|                                          |" << endl;

    for (int i = 0; i < menu.dishGroups.size(); i++) {
        cout << "|" << "  " << menu.dishGroups[i].getName() << string(40 - menu.dishGroups[i].getName().length(), ' ')
             << "|" << endl;
        for (int j = 0; j < menu.dishGroups[i].dishes.size(); j++) {
            printItem(menu.dishGroups[i].dishes[j]);
        }
    }

    cout << "|                                          |" << endl;
    cout << "--------------------------------------------" << endl;

}

double printCurrentOrder(Menu menu, vector<int> currentOrder) {

    double suma = 0;

    for (int i = 0; i < currentOrder.size(); i++) {
        if (i == 0 || currentOrder[i] != currentOrder[i - 1]) {
            int ID = currentOrder[i];
            string NAME = menu.findDish(ID).getName();
            int AMOUNT = count(currentOrder.begin(), currentOrder.end(), ID); // Заменить на getAmount
            double PRICE = menu.findDish(ID).getPrice() * AMOUNT;

            cout << "    - [";
            if (ID < 10) { cout << 0; }
            cout << ID << "] " << NAME << string(31 - NAME.length(), '.') << " x" << AMOUNT << " = ";
            if (PRICE < 10) { cout << 0; }
            cout << PRICE << endl;

            suma += PRICE;
        }
    }

    cout << endl;
    cout << "Suma: " << suma << endl;
    cout << endl;

    return suma;
}

int myRand(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

string generateid() {
    string gen;
    for (int i = 0; i < 10; i++) {
        char zxc = myRand(97, 122);
        gen += zxc;
    }
    return gen;
}

int getFoodId(Menu menu, string operacja) {
    int foodid = -1;
    while (menu.isCorrectID(foodid) == false) {
        cout << "Proze podac number id dania (0 - skonczyc " << operacja << "): ";
        cin >> foodid;
        if (foodid == 0) {
            cin.clear();
            return 0;
        } else if (menu.isCorrectID(foodid) == true) {
            return foodid;
        } else {
            cout << "ERROR!!! ID dania nie istnieje!" << endl;
            cin.clear();
        }
    }
    return foodid;
}

void crOrder(Menu menu) {
    int i = -1;

    time_t seconds = time(NULL);
    tm *timeinfo = localtime(&seconds);

    Date date(timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);

    Order order(date, generateid());

    while (order.dishes.size() < 10 && i != 0) {
        cout << "Proze podac id dania: ";
        cin >> i;

        while (!menu.isCorrectID(i) && i != 0) {
            cout << "ERROR!!! ID dania nie istnieje!" << endl;
            cout << "Proze podac number id dania: ";
            cin >> i;
        }

        if (i == 0) {
            break;
        }

        order.addDishToOrder(menu.findDish(i));
        order.dishes.size();
    }

    cout << endl;
    cout << "Suma dań: " << order.dishes.size() << endl;
    cout << endl;

    vector<int> ID;
    for (i = 0; i < order.dishes.size(); i++) {
        for (int j = 0; j < order.dishes[i].getAmount(); j++) {
            ID.push_back(order.dishes[i].getMenuID());
        }
    }
    printCurrentOrder(menu, ID);

    while (true) {
        string opcja;

        cout
                << "--------------------------\n[0] = Skonczyc zamówienie\n[1] = Dodac danie\n[2] = Usunąć danie\n--------------------------"
                << endl;
        cout << "Podaj opcje: ";
        cin >> opcja;
        cout << endl;
        if (opcja == "0") {
            break;
        } else if (opcja == "1") {
            if (order.dishes.size() == 10) {
                cout << "Limit pszekroczony!" << endl;
            }
            while (order.dishes.size() < 10) {

                int foodid;

                foodid = getFoodId(menu, "dodawanie");
                if (foodid == 0) {
                    break;
                }
                order.addDishToOrder(menu.findDish(foodid));
            }
        } else if (opcja == "2") {
            if (order.dishes.size() == 0) {
                cout << "Nie można usunąć danie (Zamówienie jest puste)" << endl;
            }
            while (order.dishes.size() > 0) {
                int foodid;
                foodid = getFoodId(menu, "usuniecie");
                if (foodid == 0) {
                    break;
                }
                order.removeDishFromOrder(menu.findDish(foodid));
            }
        } else {
            cout << "Nie istnieje takiej opcji!";
        }
    }
    vector<int> alldish;
    for (int i = 0; i < order.dishes.size(); i++) {
        for (int j = 0; j < order.dishes[i].getAmount(); j++) {
            alldish.push_back(order.dishes[i].getMenuID());
        }
    }
    printCurrentOrder(menu, alldish);

    if (order.dishes.size() != 0) {
        WriteNewOrderToHistory(order);
    }
}

void printHistory() {
    vector<Order> order = ReadHistoryData();
    printHistoryHead();
    double Suma = 0;
    for (int i = 0; i < order.size(); i++) {
        printHistoryBody(i + 1, 0, true, order[i]);
        for (int j = 1; j < order[i].dishes.size(); j++) {
            printHistoryBody(i + 1, j, false, order[i]);
        }
        Suma += order[i].calculateOrderCost();
        printHistorySum(order[i].calculateOrderCost());
    }
    printHistoryTotalSum(Suma);
}

Date readDate() {
    bool corr = false;
    int day;
    int month;
    int year;
    while (corr == false) {
        cout << "!Pierwsza data: 11.01.2022!" << endl;
        cout << endl;
        cout << "Wpiszcie datu(dd.mm.yyyy)" << endl;
        cout << "Dzień: ";
        cin >> day;
        cout << "Miesiąnc: ";
        cin >> month;
        cout << "Rok: ";
        cin >> year;

        if (0 < day || 0 < month || month > 12 || 2022 == year) {
            if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
                day < 31)
                corr = true;
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 30)
                corr = true;
            else {
                (month == 2 && day < 28);
                corr = true;
            }
        }
        if (corr != true) {
            cout << "Data wpisana nie poprawnie" << endl;
        }
    }
    Date date(year, month, day);
    return date;

}


void printHistoryOnDate() {
    Date date = readDate();
    vector<Order> order = ReadHistoryDataOnDay(date);
    printHistoryHead();
    double Suma = 0;
    for (int i = 0; i < order.size(); i++) {
        printHistoryBody(i + 1, 0, true, order[i]);
        for (int j = 1; j < order[i].dishes.size(); j++) {
            printHistoryBody(i + 1, j, false, order[i]);
        }
        Suma += order[i].calculateOrderCost();
        printHistorySum(order[i].calculateOrderCost());
    }
    printHistoryTotalSum(Suma);

}


int main() {

    cout << "-----------------------------------------" << endl;
    string name = ReadGeneralData();
    cout << name << endl;
    cout << "-----------------------------------------" << endl;

    cout << endl;
    cout << "Witaj w programie Restauracja 1.0" << endl;
    cout << endl;

    while (true) {

        callMainMenu();

        int choice = -1;

        while (choice < 0 || choice > 3) {
            cout << "Proszę podać opcje: ";
            cin >> choice;
            if (choice < 0 || choice > 3) {
                cout << "ERROR!!! Opcja nie istnieje!" << endl;
            }
        }
        cout << endl;

        Menu menu = ReadMenuData();

        switch (choice) {
            case 0:
                cout << "Do widzenia! Czekamy na państwo znowu.";
                return EXIT_SUCCESS;
            case 1:
                printMenu(menu);

                cout << endl;
                cout << "Proszę podać numery id dań jakie mają zostać dodane do zamóvienia," << endl
                     << "wpisanie 0 spowoduje przejście do następnego kroku." << endl;
                cout << endl;

                crOrder(menu);
                break;
            case 2:
                printHistory();
                break;
            case 3:
                printHistoryOnDate();
                break;
            default:
                break;
        }
    }
}

