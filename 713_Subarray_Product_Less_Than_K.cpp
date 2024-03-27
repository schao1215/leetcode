#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        int front_idx = 0;
        for(int i=0;i<nums.size();i++){
            mul *= nums[i];
            while(mul >= k && front_idx < i){
                mul /= nums[front_idx];
                front_idx++;
            }
            if(mul < k)
                ans += (i - front_idx + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1, 2, 3};
    int k = 0;
    Solution s;
    int ans = s.numSubarrayProductLessThanK(nums, k);
    cout<<ans<<endl;
}