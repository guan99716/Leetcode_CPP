#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> um;
        int maxLen = 0;
        for(int n: nums){
            um[n]++;
        }
        for(auto &[key,val] : um){
            if(um.count(key+1))
                maxLen = max(maxLen, um[key]+um[key+1]);
        }
        return maxLen;
        
    }
};