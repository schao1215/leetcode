#include <iostream>
using namespace std;
typedef long long ll;

class Solution {
public:
    ll largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for(int num:nums)   ans += num;
        for(int i=0;i<nums.size() - 2;i++){
            if(ans - nums[nums.size() - 1 - i] > nums[nums.size() - 1 - i])
                return ans;
            else{
                ans -= nums[nums.size() - 1 - i];
            }
        }
        return -1;        
    }
};

int main(){
    vector<int> nums = {1, 2, 5};
    Solution s;
    ll ans = s.largestPerimeter(nums);
    cout<<ans<<endl;
}