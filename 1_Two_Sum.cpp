#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!m.count(target - nums[i]))   m[nums[i]] = i;
            else    return ans = {i, m[target-nums[i]]};
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-1,-2,-3,-4,-5};
    int target = -8;
    Solution s;
    for(int ans:s.twoSum(nums, target)) cout<<ans<<" ";
    cout<<endl;
}