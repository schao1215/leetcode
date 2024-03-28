#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        // int max_cnt = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(right=0;right<nums.size();right++){
            mp[nums[right]] ++;
            if(mp[nums[right]] <= k){
                // max_cnt = max(max_cnt, mp[nums[right]]);
                ans = max(ans, right - left + 1);
            }
            else{
                while(mp[nums[right]] > k){
                    mp[nums[left++]] --;
                    // left ++;
                    // cout<<left<<endl;
                }
            }
            // cout<<right<<endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nums{5,5,5,5,5,5,5,55};
    int k = 4;
    Solution s;
    int ans = s.maxSubarrayLength(nums, k);
    cout<<ans<<endl;
}