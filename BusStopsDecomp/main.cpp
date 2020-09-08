#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>
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
    string query_str;
    cin >> query_str;

    if(query_str == "NEW_BUS") {
        q.type = QueryType::NewBus;
    } else if(query_str == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
    } else if(query_str == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
    } else if(query_str == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    if(q.type == QueryType::NewBus) {
        q.stops.clear();
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
    vector<string>buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    if(!r.buses.empty()) {
            for(auto& bus : r.buses) {
                cout << bus << " ";
            }
    } else {
        cout << "No stop";
    }
    return os;
}

struct StopsForBusField {
    string stop_name;
    vector<string>buses;
};

struct StopsForBusResponse {
    vector<StopsForBusField>stops_for_buses_response;
};



ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    if(!r.stops_for_buses_response.empty()) {
        int i = r.stops_for_buses_response.size();
        for(auto& stop : r.stops_for_buses_response) {
            cout << "Stop " << stop.stop_name << ": ";
            if(!stop.buses.empty()) {
                for(auto& buses : stop.buses) {
                    cout << buses << " ";
                }
            } else {
                cout << "no interchange";
            }
        i--;
        if(i != 0) {
            cout << endl;
            }
        }
    } else {
        cout << "No bus";
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    if(!r.buses.empty()) {
        int i = r.buses.size();
        for(auto& bus : r.buses) {
            cout << "Bus " << bus.first << ": ";
            for(auto& stops : bus.second) {
                cout << stops << " ";
            }
            i--;
            if(i != 0) {
                cout << endl;
            }
        }
    } else {
        cout << "No buses";
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        //остановка -> автобусы
        buses_to_stops[bus] = stops;
        for(auto& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
        BusesForStopResponse result;
        if(stops_to_buses.count(stop)) {
            result.buses = stops_to_buses.at(stop);
        }
        return result;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
        StopsForBusResponse result;
        if(buses_to_stops.count(bus)) {
            for(const string& stop : buses_to_stops.at(bus)) {
                //cout << "Debug: " << stop << endl;
                StopsForBusField result_item;
                result_item.stop_name = stop;
                for(const string& other_bus : stops_to_buses.at(stop)) {
                    if(bus != other_bus) {
                        result_item.buses.push_back(other_bus);
                    }
                }
                result.stops_for_buses_response.push_back(result_item);
            }
        }
        return result;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse result;
        result.buses = buses_to_stops;
        return result;
    }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
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
