#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    uint32_t blocks_count;
    uint16_t density;

    cin >> blocks_count >> density;

    vector<uint64_t>block_size;

    while(blocks_count !=0) {
        uint16_t w = 0;
        uint16_t h = 0;
        uint16_t d = 0;
        cin >> w >> h >> d;
        uint64_t volume = static_cast<uint64_t>(w) * h * d;
        block_size.push_back(volume);
        blocks_count--;
    }

    uint64_t weight = 0;

    for(auto& vol : block_size) {
        uint64_t weight_item = vol * density;
        weight += weight_item;
    }

    cout << weight;

    return 0;
}
