#include <iostream>
#include <vector>
#include <algorithm>
//#include "test_framework.h"
using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    vector<int> result;
    //get it on first negative num from vector or it on last elem
    auto negative_num = find_if(begin(numbers), end(numbers),
        [](const int num) {
            return num < 0;
        });

    if (!numbers.empty()) {
        if (negative_num != begin(numbers) && negative_num != end(numbers)) {
            //if neg num was searched, but not first elem
            auto exclude_r_border = negative_num;
            while (exclude_r_border != begin(numbers)) {
                exclude_r_border--; //step right <- left
                result.push_back(*exclude_r_border);
            }
            for (auto& item : result) {
                cout << item << " ";
            }
        }
        else if (negative_num == end(numbers)) {
            //have no neg nums in vec
            result = numbers;
            reverse(begin(result), end(result));
            for (auto& item : result) {
                cout << item << " ";
            }
        }
    }
}

/*
vector<int> GetVectorPart(const vector<int>& numbers) {
    vector<int> result;
    //get it on first negative num from vector or it on last elem
    auto negative_num = find_if(begin(numbers), end(numbers),
        [](const int num) {
            return num < 0; 
        });
    
    if (!numbers.empty()) {
        if (negative_num == end(numbers)) {
            //have no neg nums in vec
            result = numbers;
            reverse(begin(result), end(result));
        }
        else if(negative_num == begin(numbers)) {
            //return empty vector if in vec 'numbers' first elem neg num
            return result;
        }
        else {
            //if neg num was searched
            auto exclude_r_border = negative_num;
            while (exclude_r_border != begin(numbers)) {
                exclude_r_border--; //step right <- left
                result.push_back(*exclude_r_border);
            }
        }
    }
     
    return result;
}


void TestPrintVectorPart() {
    vector<int> in_1 = { 6, 1, 8, -5, 4 };
    vector<int> out_1 = { 8, 1, 6 };
    AssertEqual(GetVectorPart(in_1), out_1, "Case 1");

    vector<int> in_2 = { -6, 1, 8, -5, 4 };
    vector<int> out_2 = {  };
    AssertEqual(GetVectorPart(in_2), out_2, "Case 2. First element are already negative");
    
    vector<int> in_3 = { 6, 1, 8, 5, 4 };
    vector<int> out_3 = { 4, 5, 8, 1, 6 };
    AssertEqual(GetVectorPart(in_3), out_3, "Case 3. Reverse vector if not have negative num");

    vector<int> in_4 = {  };
    vector<int> out_4 = {  };
    AssertEqual(GetVectorPart(in_4), out_4, "Case 4. Empty vec");
}
*/

int main() {
    //TestRunner tr;
    //tr.RunTest(TestPrintVectorPart, "TestPrintVectorPart");
    
    return 0;
}