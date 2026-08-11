#include <vector>
using namespace std;
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int p = m + n - 1;
            m--;
            n--;
            while (p > 0){
                if(nums1[m] > nums2[n]){
                    nums1[p] = nums1[m];
                    m--;
                }
                else{
                    nums1[p] = nums2[n];
                    n--;
                }
                p--;
            }       
        }
    };