#pragma once
#include <string>
#include <vector>
#include <ostream>
#include <map>

using namespace std;

struct StopsForBusField {
    string stop_name;
    vector<string>buses;
};

struct BusesForStopResponse {
    // Наполните полями эту структуру
    vector<string>buses;
};

struct StopsForBusResponse {
    vector<StopsForBusField>stops_for_buses_response;
};

struct AllBusesResponse {
    map<string, vector<string>> buses;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);
ostream& operator << (ostream& os, const StopsForBusResponse& r);
ostream& operator << (ostream& os, const AllBusesResponse& r);