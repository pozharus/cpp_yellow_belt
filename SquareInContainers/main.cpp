#include <iostream>
#include <vector>
#include <map>
using namespace std;
template<typename T> auto Sqr(const T& container);

template<typename T>
vector<T> operator * (const vector<T>& lhs_v, const vector<T>& rhs_v);
template<typename Index, typename Value>
map<Index, Value> operator * (const map<Index, Value> lhs_map,
                              const map<Index, Value> rhs_map);
template<typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& lhs_pair,
                                const pair<First, Second>& rhs_pair);

template<typename T> auto Sqr(const T& container) {
    return container * container;
}

template<typename T> //vector
vector<T> operator * (const vector<T>& lhs_v, const vector<T>& rhs_v) {
    vector<T>result;
    for(auto& item : lhs_v) {
        result.push_back(item * item);
    }
    return result;
}

template<typename Index, typename Value> //map
map<Index, Value> operator * (const map<Index, Value> lhs_map,
                              const map<Index, Value> rhs_map) {
    map<Index, Value> result;
    for(auto& lhs : lhs_map) {
        result[lhs.first] = lhs.second * lhs.second;
    }
    return result;
}

template<typename First, typename Second> //pair
pair<First, Second> operator * (const pair<First, Second>& lhs_pair,
                                const pair<First, Second>& rhs_pair) {
    pair<First, Second> result;
        result.first = lhs_pair.first * rhs_pair.first;
        result.second = rhs_pair.second * rhs_pair.second;
    return result;
}

int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
