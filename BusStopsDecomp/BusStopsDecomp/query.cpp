#include <ostream>
#include <iostream>
#include "query.h"
using namespace std;

istream& operator >> (istream& is, Query& q) {
    //Реализуйте эту функцию
    //Вводим команду
    string query_str;
    cin >> query_str;

    if (query_str == "NEW_BUS") {
        q.type = QueryType::NewBus;
    }
    else if (query_str == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
    }
    else if (query_str == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
    }
    else if (query_str == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    if (q.type == QueryType::NewBus) {
        q.stops.clear();
        cin >> q.bus; //имя автобуса
        int stop_count;
        cin >> stop_count;
        while (stop_count != 0) {
            cin >> q.stop;
            q.stops.push_back(q.stop);
            stop_count--;
        }
    }

    if (q.type == QueryType::StopsForBus) {
        cin >> q.bus;
    }

    if (q.type == QueryType::BusesForStop) {
        cin >> q.stop;
    }

    return is;
}