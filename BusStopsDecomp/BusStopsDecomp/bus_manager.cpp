#include <string>
#include <vector>
#include <map>
#include "bus_manager.h"
#include "responses.h"
using namespace std;


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    //остановка -> автобусы
    buses_to_stops[bus] = stops;
    for (auto& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse result;
    if (stops_to_buses.count(stop)) {
        result.buses = stops_to_buses.at(stop);
    }
    return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse result;
    if (buses_to_stops.count(bus)) {
        for (const string& stop : buses_to_stops.at(bus)) {
            //cout << "Debug: " << stop << endl;
            StopsForBusField result_item;
            result_item.stop_name = stop;
            for (const string& other_bus : stops_to_buses.at(stop)) {
                if (bus != other_bus) {
                    result_item.buses.push_back(other_bus);
                }
            }
            result.stops_for_buses_response.push_back(result_item);
        }
    }
    return result;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse result;
    result.buses = buses_to_stops;
    return result;
}
