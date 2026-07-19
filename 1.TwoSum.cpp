#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
      if (um.count(nums[i])) {
        return {um[nums[i]], i};
      } else {
        um[target - nums[i]] = i;
      }
    }
    return {};
  }
};