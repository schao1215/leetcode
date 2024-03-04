#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int cnt = 0;
        for(int num:nums){
            if(num == 0)    cnt += 1;
        }
        if(cnt >= 2)    return ans;
        if(cnt == 1){
            int prod = 1;
            int tmp = 0;
            for(int i=0;i<nums.size();i++){
                nums[i] == 0 ? tmp = i : prod *= nums[i];
            }
            ans[tmp] = prod;
            return ans;
        }
        int prod = 1;
        for(int i=0;i<nums.size();i++){
            ans[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums{-1, 1, 0, 3, -3};
    Solution s;
    vector<int> ans = s.productExceptSelf(nums);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
}