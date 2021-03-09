#include "../../UnitTestFramework/test_runner.h"; //TODO: comment before sending to coursera
//#include "test_runner.h" //comment before working
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    
    auto right = find(begin(s), end(s), ' '); //get space after first word
    result.push_back(string(begin(s), right)); //push first word in vec

    auto left = right;
	/*shifting left-right pair*/
    while (right != end(s)) {
        right = find((++left), end(s), ' '); //search new right (it would be first char after space
        result.push_back(string(left, right));
        left = right;
    }

    return result;
}

void TestSplitIntoWords() {
    string in = "C Cpp Java Python";
    vector<string> out = { "C", "Cpp", "Java", "Python" };
    AssertEqual(SplitIntoWords(in), out, "Case 1");
}

int main()
{
    TestRunner tr;
    tr.RunTest(TestSplitIntoWords, "TestSplitIntoWords");    
}