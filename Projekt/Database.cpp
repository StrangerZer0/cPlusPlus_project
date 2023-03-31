#include "Database.h"

Dish::Dish(string _name, double _price) {
    name = _name;
    if (_price < 0) {
        throw invalid_argument("In the dish named '" + name + "' : You are trying to set price " + to_string(_price) +
                               " that is less than 0, but it's not allowed!");
    }
    price = _price;
    amount = 1;
    menuid = 0;
}

Dish::Dish(string _name, double _price, int _menuid) {
    name = _name;
    if (_price < 0) {
        throw invalid_argument("In the dish named '" + name + "' : You are trying to set price " + to_string(_price) +
                               " that is less than 0, but it's not allowed!");
    }
    price = _price;
    amount = 1;
    menuid = _menuid;
}

string Dish::getName() {
    return name;
}

int Dish::getAmount() {
    return amount;
}

int Dish::getMenuID() {
    return menuid;
}

void Dish::setAmount(int value) {
    if (value <= 0) {
        throw invalid_argument("In the dish named '" + name + "' : You are trying to set amount " + to_string(value) +
                               " that is less or equal to 0, but it's not allowed!");
    }
    amount = value;
}

double Dish::getPrice() { return price; }


Date::Date() {}

Date::Date(int _year, int _month, int _day) {
    setYear(_year);
    setMonth(_month);
    setDay(_day);
}

string Date::getStringDate() {
    string monthS = "";
    if (month < 10) monthS += "0";
    monthS += to_string(month);


    string dayS = "";
    if (day < 10) dayS += "0";
    dayS += to_string(day);

    return to_string(year) + "-" + monthS + "-" + dayS;
}

void Date::setYear(int value) {
    if (value < 0) {
        throw invalid_argument(
                "You are trying to set year " + to_string(value) + " that is less than 0, but it's not allowed!");
    }
    year = value;
}

void Date::setMonth(int value) {
    if (value < 0 || value > 12) {
        throw invalid_argument("You are trying to set month " + to_string(value) + " that doesn't exist!");
    }
    month = value;
}

void Date::setDay(int value) {
    if (value < 1) {
        throw invalid_argument(
                "You are trying to set day " + to_string(value) + " that is less than 1, but it's not allowed!");
    }
    if (value > 31) {
        throw invalid_argument(
                "You are trying to set day " + to_string(value) + " that is more than 31, but it's not allowed!");
    }
    day = value;
}

bool Date::isLaterThan(Date other) {
    if (year > other.year) {
        return true;
    } else if (year < other.year) {
        return false;
    } else if (month > other.month) {
        return true;
    } else if (month < other.month) {
        return false;
    } else if (day > other.day) {
        return true;
    } else {
        return false;
    }
}

bool Date::isEqualTo(Date other) {
    return year == other.year && month == other.month && day == other.day;
}


Order::Order(Date _date, string _id) {
    date = _date;
    id = _id;
}

Date Order::getDate() { return date; }

string Order::getID() { return id; }

void Order::addDishToOrder(Dish dish) {
    for (int i = 0; i < dishes.size(); i++) {
        if (dish.getName() == dishes[i].getName()) {
            dishes[i].setAmount(dishes[i].getAmount() + dish.getAmount());
            return;
        }
    }
    dishes.push_back(dish);
}

void Order::removeDishFromOrder(Dish dish) {
    for (int i = 0; i < dishes.size(); i++) {
        if (dish.getName() == dishes[i].getName()) {
            dishes.erase(dishes.begin() + i);
            return;
        }
    }
}

double Order::calculateOrderCost() {
    double sum = 0;
    for (int i = 0; i < dishes.size(); i++) {
        sum += dishes[i].getAmount() * dishes[i].getPrice();
    }
    return sum;
}


DishGroup::DishGroup(string _name) { name = _name; }

string DishGroup::getName() { return name; }

bool Menu::isCorrectID(int id) {
    int amount = 0;
    for (int i = 0; i < dishGroups.size(); i++) {
        for (int d = 0; d < dishGroups[i].dishes.size(); d++) {
            if (dishGroups[i].dishes[d].getMenuID() == id) {
                return true;
            }
        }
    }
    return false;
}

Dish Menu::findDish(int id) {
    for (int i = 0; i < dishGroups.size(); i++) {
        for (int d = 0; d < dishGroups[i].dishes.size(); d++) {
            if (dishGroups[i].dishes[d].getMenuID() == id) {
                return dishGroups[i].dishes[d];
            }
        }
    }
    throw invalid_argument("No dish with ID " + to_string(id) + " in the menu!");
}




