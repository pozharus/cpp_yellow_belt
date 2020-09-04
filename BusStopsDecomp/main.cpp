#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    //Реализуйте эту функцию
    //Вводим команду
    if(q.type == QueryType::NewBus) {
        cin >> q.bus;
        int stop_count;
        cin >> stop_count;
        while (stop_count != 0) {
            cin >> q.stop;
            q.stops.push_back(q.stop);
            stop_count--;
        }
    }

    if(q.type == QueryType::StopsForBus) {
        cin >> q.bus;
    }

    if(q.type == QueryType::BusesForStop) {
        cin >> q.stop;
    }

    return is;
}

struct BusesForStopResponse {
    // Наполните полями эту структуру

};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    return os;
}

struct StopsForBusResponse {

};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру

};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        // Реализуйте этот метод

    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
    }

    AllBusesResponse GetAllBuses() const {
        // Реализуйте этот метод

    }
private:

};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q; //Вводим имя команды
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
