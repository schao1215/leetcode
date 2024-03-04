#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int rem = size * (size + 1) / 2;
        for(int num:nums)   rem -= num;
        return rem;
    }
};

int main(){
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    Solution s;
    int ans = s.missingNumber(nums);
    cout<<ans<<endl;
}