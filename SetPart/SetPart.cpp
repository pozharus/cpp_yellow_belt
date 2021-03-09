#include "test_runner.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;
    auto l_border = upper_bound(begin(elements), end(elements), border);
    for (auto it = l_border; it != end(elements); ++it) { //loop by [begin, end]
        //if elements in (begin, end] range put it
        result.push_back(*it);     
    }

    return result;
}

void TestFindGreaterElements() {
    set<int> in = {1, 5, 7, 8};
    vector<int> expected = { 7, 8 };
    int to_find = 5;
    AssertEqual(FindGreaterElements(in, to_find), expected, "Case 1");

    set<int> in2 = { 1, 5, 7, 8 };
    vector<int> expected2 = { 7, 8 };
    int to_find2 = 6;
    AssertEqual(FindGreaterElements(in2, to_find2), expected2, "Case 2");
    
    /*
    set<string> in2 = { "C", "C++" };
    vector<string> expected2 = { };
    string to_find2 = "Python";
    AssertEqual(FindGreaterElements(in2, to_find2), expected2, "Case 2. Don't find any matches");

    set<string> in3 = { "C", "C++", "Python"};
    vector<string> expected3 = {  };
    string to_find3 = "Python";
    AssertEqual(FindGreaterElements(in3, to_find3), expected3, "Case 3. String last match");

    set<string> in4 = { "C", "C++", "Java", "Python"};
    vector<string> expected4 = { "Python" };
    string to_find4 = "Java";
    AssertEqual(FindGreaterElements(in4, to_find4), expected4, "Case 4. String pre-last match");

    set<string> in5 = { "C", "C++", "Java", "Python" };
    vector<string> expected5 = { "C++", "Java", "Python" };
    string to_find5 = "C";
    AssertEqual(FindGreaterElements(in5, to_find5), expected5, "Case 5. String first match");

    set<int> in6 = { 1 };
    vector<int> expected6 = { };
    int to_find6 =  1;
    AssertEqual(FindGreaterElements(in6, to_find6), expected6, "Case 6. One from one elem");

    set<int> in7 = { 1, 1, 4, 6, 7, 8};
    vector<int> expected7 = { 4, 6, 7, 8 };
    int to_find7 = 1;
    AssertEqual(FindGreaterElements(in7, to_find7), expected7, "Case 7. Empty vec");
    */
}

int main()
{
    TestRunner tr;
    tr.RunTest(TestFindGreaterElements, "Test FindGreaterElements");    

    return 0;
}