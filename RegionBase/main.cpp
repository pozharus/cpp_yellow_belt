#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions) {
    if(regions.size() == 0) {
        return 0;
    } else {
        set<int>numbers;


        for(auto& region : regions) {
            numbers.insert(count(cbegin(regions),cend(regions),region));
        }

        int num = *numbers.rbegin();
        numbers.clear();
        return num;
    }
}

auto GetTuple(const Region& region) {
    return tie(region.std_name, region.parent_std_name, region.names,region.population);
}

bool operator == (const Region& lhs_region, const Region& rhs_region) {
    return GetTuple(lhs_region) == GetTuple(rhs_region);
}

int main() {
    cout << FindMaxRepetitionCount({
   {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Russia",
           "Eurasia",
           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
           89
   }, {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Russia",
           "Eurasia",
           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
           89
   },
   }) << endl;

    cout << FindMaxRepetitionCount({
   {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Russia",
           "Eurasia",
           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
           89
   }, {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Moscow",
           "Toulouse",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           89
   }, {
           "Moscow",
           "Russia",
           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
           31
   },
}) << endl;

    return 0;
}

