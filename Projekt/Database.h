#include <iostream>
#include <vector>

using namespace std;

#ifndef FILEIOENGINE_DATABASE_H
#define FILEIOENGINE_DATABASE_H

struct Dish {
public:
    Dish(string _name, double _price);

    Dish(string _name, double _price, int _menuid);

    string getName();

    int getAmount();

    int getMenuID();

    void setAmount(int value);

    double getPrice();

private:
    string name = "";
    double price = 0;
    int amount = 0;
    int menuid = 0;
};

struct Date {
public:
    Date();

    Date(int _year, int _month, int _day);

    string getStringDate();

    void setYear(int value);

    void setMonth(int value);

    void setDay(int value);

    bool isLaterThan(Date other);

    bool isEqualTo(Date other);

private:
    int year = 2022;
    int month = 1;
    int day = 1;
};

struct Order {
public:
    Order(Date _date, string _id);

    Date getDate();

    string getID();

    void addDishToOrder(Dish dish);

    void removeDishFromOrder(Dish dish);

    double calculateOrderCost();

    vector<Dish> dishes;


private:
    Date date;
    string id = "";
};

struct DishGroup {
public:
    DishGroup(string _name);

    string getName();

    vector<Dish> dishes;

private:
    string name = "";
};

struct Menu {
public:
    vector<DishGroup> dishGroups;

    bool isCorrectID(int id);

    Dish findDish(int id);
};

#endif
