#include <iostream>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s = nums[0], m = INT_MAX;
        for(int num:nums){
            if(num > m)  return true;
            if(num < s) s = num;
            if(num > s && num < m)  m = num;
        }
        return false;
    }
};

int main(){
    vector<int> nums{10, 11, 0, 1, 3};
    Solution s;
    bool ans = s.increasingTriplet(nums);
    cout<<ans<<endl;
}