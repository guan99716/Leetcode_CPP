#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j] && j + 1 < nums.max_size()) {
                j++;
                nums[j] = nums[i];
            }
        }
        // index j means it is of length j + 1
        return j + 1;
    }
};