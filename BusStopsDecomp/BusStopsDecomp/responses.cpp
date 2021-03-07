#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "responses.h"
using namespace std;

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    if (!r.stops_for_buses_response.empty()) {
        int i = r.stops_for_buses_response.size();
        for (auto& stop : r.stops_for_buses_response) {
            cout << "Stop " << stop.stop_name << ": ";
            if (!stop.buses.empty()) {
                for (auto& buses : stop.buses) {
                    cout << buses << " ";
                }
            }
            else {
                cout << "no interchange";
            }
            i--;
            if (i != 0) {
                cout << endl;
            }
        }
    }
    else {
        cout << "No bus";
    }
    return os;
}

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    if (!r.buses.empty()) {
        for (auto& bus : r.buses) {
            cout << bus << " ";
        }
    }
    else {
        cout << "No stop";
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    if (!r.buses.empty()) {
        int i = r.buses.size();
        for (auto& bus : r.buses) {
            cout << "Bus " << bus.first << ": ";
            for (auto& stops : bus.second) {
                cout << stops << " ";
            }
            i--;
            if (i != 0) {
                cout << endl;
            }
        }
    }
    else {
        cout << "No buses";
    }
    return os;
}


