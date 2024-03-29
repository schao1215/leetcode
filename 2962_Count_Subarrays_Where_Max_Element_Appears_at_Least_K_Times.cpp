#include <iostream>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = 0;
        for(int ele:nums)   max_ele = max(max_ele, ele);

        // sliding window
        long long ans = 0;
        vector<int> pos;
        for(int i=0;i<nums.size();i++)  if(nums[i] == max_ele)  pos.push_back(i);
        // for(int ele:pos)   cout<<ele<<" ";
        // cout<<endl;
        if(pos.size() < k)  return 0;
        for(int i=k-1;i<pos.size()-1;i++){
            ans += (pos[i-k+1]+1)*(pos[i+1]-pos[i]);
        }
        ans += (pos[pos.size()-k]+1)*(nums.size()-pos[pos.size()-1]);
        return ans;
    }
};

int main(){
    vector<int> nums{37,20,38,66,34,38,9,41,1,14,25,63,8,12,66,66,60,12,35,27,16,38,12,66,38,36,59,54,66,54,66,48,59,66,34,11,50,66,42,51,53,66,31,24,66,44,66,1,66,66,29,54};
    int k = 5;
    Solution s;
    long long ans = s.countSubarrays(nums, k);
    cout<<ans<<endl;
}