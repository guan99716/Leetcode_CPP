#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            int temp = nums[n - 1];
            cout << temp << '\n';
            for (int j = n-2; j >= 0; j--) {
                nums[j + 1] = nums[j];
            }
            nums[0] = temp;
        }
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    Solution s;
    s.rotate(v, 3);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}