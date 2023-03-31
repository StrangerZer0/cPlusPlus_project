#include <vector>
#include "Database.h"

using namespace std;

#ifndef fileioengine_h
#define fileioengine_h

string ReadGeneralData();

Menu ReadMenuData();

vector<Order> ReadHistoryData();

vector<Order> ReadHistoryDataOnDay(Date date);

void WriteNewOrderToHistory(Order order);

#endif
