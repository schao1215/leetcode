#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0, diff = 0;
        for(int i=0;i<nums.size();i++){
            (nums[i] == 1) ? diff += 1 : diff -= 1;
            if(mp.find(diff) != mp.end()){
                ans = max(ans, i - mp[diff]);
            }
            else
                mp[diff] = i;
        }
        return ans;
    }
};

int main(){
    vector<int> nums{0, 1};
    Solution s;
    int ans = s.findMaxLength(nums);
    cout<<ans<<endl;
}