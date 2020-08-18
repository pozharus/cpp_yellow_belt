#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
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

auto GetTuple(const Region& region) {
    tie(region.std_name, region.parent_std_name,region.names,region.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    for(size_t i = 0; i < regions.size(); i++) {

    }
}

bool operator == (Region& lhs, Region& rhs) {
    if(lhs.std_name != rhs.std_name) {
        return false;
    }
    if(lhs.parent_std_name != rhs.parent_std_name) {
        return false;
    }

    return lhs.population == rhs.population; //Тогда сравниваем самое крайнее поле
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
