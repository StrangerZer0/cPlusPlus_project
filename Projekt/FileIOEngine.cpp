#include <string>
#include <fstream>
#include <vector>
#include "FileIOEngine.h"

using namespace std;

string ParseLineID(string text) {
    string value = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '=') {
            break;
        } else {
            value += text[i];
        }
    }
    return value;
}

string ParseLineValue(string text) {
    string value = "";
    bool read = false;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '=') {
            if (read) {
                value += text[i];
            } else {
                read = true;
            }
        } else {
            if (read) {
                value += text[i];
            }
        }
    }
    return value;
}

Date ParseStringToDate(string dateS) {
    Date date;
    string value = "";
    int level = 0;
    for (int i = 0; i < dateS.length(); i++) {
        if (dateS[i] == '-') {
            if (level == 0) {
                date.setYear(stoi(value));
            } else if (level == 1) {
                date.setMonth(stoi(value));
            }
            value = "";
            level++;
        } else {
            value += dateS[i];
        }
    }
    date.setDay(stoi(value));
    return date;
}

vector<string> ReadFileTXTFromDatabase(string fileName) {
    vector<string> result;
    ifstream stream("data/" + fileName);
    if (stream.is_open()) {
        while (!stream.eof()) {
            string line = "";
            getline(stream, line);
            result.push_back(line);
        }
        stream.close();
    } else {
        throw runtime_error("ERROR: cannot open file named \"" + fileName +
                            "\". Check if there is a file in the same directory as .exe file of your application");
    }

    return result;
}

void WriteLinesToTXTInDatabase(string fileName, vector<string> lines) {
    vector<string> result;
    ofstream stream("data/" + fileName, ios::app);
    if (stream.is_open()) {
        for (int i = 0; i < lines.size(); i++) {
            stream << lines[i] << "\n";
        }
        stream.close();
    } else {
        throw runtime_error("ERROR: cannot open file named \"" + fileName +
                            "\". Check if there is a file in the same directory as .exe file of your application");
    }
}


string ReadGeneralData() {
    vector<string> text;
    text = ReadFileTXTFromDatabase("setup.txt");
    string result = ParseLineValue(text[0]);
    return result;
}

Menu ReadMenuData() {
    Menu menu;
    vector<string> text;
    text = ReadFileTXTFromDatabase("menu.txt");
    vector<string> groups;
    for (int i = 0; i < text.size(); i++) {
        groups.push_back(ParseLineValue(text[i]));
    }
    int id = 1;
    for (int i = 0; i < groups.size(); i++) {
        text = ReadFileTXTFromDatabase(groups[i] + ".txt");
        DishGroup group(ParseLineValue(text[0]));

        for (int d = 0; d < text.size() / 2; d++) {
            Dish dish(ParseLineValue(text[d * 2 + 1]), stod(ParseLineValue(text[d * 2 + 2])), id);
            id++;
            group.dishes.push_back(dish);
        }
        menu.dishGroups.push_back(group);
    }
    return menu;
}

vector<Order> ReadHistoryData() {
    vector<Order> orders;
    vector<string> text = ReadFileTXTFromDatabase("history.txt");
    string dateS = "";
    string id = "";
    vector<Dish> dishes;
    string name = "";
    string price = "";
    string amount = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == "#Order") {
            dateS = ParseLineValue(text[i + 1]);
            id = ParseLineValue(text[i + 2]);
        }
        if (text[i] == "#Dish") {
            name = ParseLineValue(text[i + 1]);
            price = ParseLineValue(text[i + 2]);
            amount = ParseLineValue(text[i + 3]);
            Dish dish(name, stod(price));
            int amountInt = stoi(amount);
            dish.setAmount(amountInt);
            dishes.push_back(dish);
        }
        if (text[i] == "#Endorder") {
            Date date = ParseStringToDate(dateS);
            Order order(date, id);
            order.dishes = dishes;
            if (orders.empty())
                orders.push_back(order);
            else {
                for (int o = 0; o < orders.size(); o++) {
                    if (date.isLaterThan(orders[o].getDate())) {
                        orders.insert(orders.begin() + o, order);
                        break;
                    } else if (o == orders.size() - 1) {
                        orders.insert(orders.begin() + o + 1, order);
                        break;
                    }
                }
            }
            dishes.clear();
        }
    }
    return orders;
}

vector<Order> ReadHistoryDataOnDay(Date date) {
    vector<Order> orders;
    vector<string> text = ReadFileTXTFromDatabase("history.txt");
    string id = "";
    vector<Dish> dishes;
    string name = "";
    string price = "";
    string amount = "";
    bool writeOrder = false;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == "#Order") {
            string dateS = ParseLineValue(text[i + 1]);
            Date orderdate = ParseStringToDate(dateS);
            if (orderdate.isEqualTo(date)) {
                writeOrder = true;
                id = ParseLineValue(text[i + 2]);
            } else {
                writeOrder = false;
            }
        }
        if (writeOrder) {
            if (text[i] == "#Dish") {
                name = ParseLineValue(text[i + 1]);
                price = ParseLineValue(text[i + 2]);
                amount = ParseLineValue(text[i + 3]);
                Dish dish(name, stod(price));
                int amountInt = stoi(amount);
                dish.setAmount(amountInt);
                dishes.push_back(dish);
            }
            if (text[i] == "#Endorder") {
                Order order(date, id);
                order.dishes = dishes;
                orders.push_back(order);
                dishes.clear();
                writeOrder = false;
            }
        }
    }
    return orders;
}

void WriteNewOrderToHistory(Order order) {
    vector<string> text;
    text.push_back("#Order");
    text.push_back("DATE=" + order.getDate().getStringDate());
    text.push_back("ID=" + order.getID());
    for (int i = 0; i < order.dishes.size(); i++) {
        text.push_back("#Dish");
        text.push_back("NAME=" + order.dishes[i].getName());
        text.push_back("PRICE=" + to_string(order.dishes[i].getPrice()));
        text.push_back("N=" + to_string(order.dishes[i].getAmount()));
    }
    text.push_back("#Endorder");
    WriteLinesToTXTInDatabase("history.txt", text);
}
