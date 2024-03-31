#include <iostream>
using namespace std;

class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        int ele_cnt = 0;
        unordered_map<int, int> mp;
        int l=0, r=0;
        while(r >= l && r < nums.size()){
            // cout<<l<<" "<<r<<endl;
            if(mp.find(nums[r]) == mp.end() || mp[nums[r]] == 0){
                ele_cnt++;
            }
            mp[nums[r]] ++;

            if(ele_cnt > k){
                while(l <= r && ele_cnt > k){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0)    ele_cnt--;
                    l++;
                }
            }
            ans += (r-l+1);
            r++;
            // cout<<"ans = "<<ans<<endl;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exact K identical element = At most K - At most (K-1)
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k-1);
    }
};

int main(){
    vector<int> nums{1,2,1,3,4};
    int k = 3;
    Solution s;
    int ans = s.subarraysWithKDistinct(nums, k);
    cout<<ans<<endl;
}