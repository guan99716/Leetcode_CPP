#include <iostream>
#include <cstdint>
using namespace std;
uint64_t isqrt(uint64_t n) {
    if (n == 0)
        return 0;
    uint64_t left = 1, right = n;
    while (left <= right) {
        uint64_t mid = left + (right - left) / 2;
        if (mid == n / mid)
            return mid;
        if (mid < n / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    int T;
    cin >> T;
    uint64_t n;
    for(int i = 0; i < T; i++) {
        cin >> n;
        // check if 1 + 8N is a perfect square
        uint64_t x = 1 + 8 * n;
        uint64_t s = isqrt(x);
        if (s * s == x && (s-1)%2==0){
            cout << "TAK" << '\n';
        }
        else{
            cout << "NIE" << '\n';
        }
    }
}