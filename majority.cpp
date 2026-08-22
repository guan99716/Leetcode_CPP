#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int maxVal = INT_MIN;
        int maxKey = 0;
        for(int num : nums){
            counter[num]++;
        }
        for(auto &[key, val] : counter){
            if(val > maxVal){
                maxVal = val;
                maxKey = key;
            }
        }
        return maxKey;
    }
};