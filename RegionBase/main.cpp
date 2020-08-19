#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
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
        map<Region, int> regions_uniq;
        for(auto& region : regions) {
            if(regions_uniq.count(region)) {
                regions_uniq.at(region)++;
            } else {
                regions_uniq[region] = 1;
            }
        }

        set<int> max_value;
            for(auto& region : regions_uniq) {
                max_value.insert(region.second);
            }
        return *max_value.rbegin();
    }
}

auto GetTuple(const Region& region) {
    return tie(region.std_name, region.parent_std_name, region.names,region.population);
}

bool operator == (const Region& lhs_region, const Region& rhs_region) {
    return GetTuple(lhs_region) == GetTuple(rhs_region);
}

bool operator < (const Region& lhs_region, const Region& rhs_region) {
    return GetTuple(lhs_region) < GetTuple(rhs_region);
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

