#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(begin(s),end(s));
    return s;
}

void Sort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
}
