#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = INT_MIN;
        for(int i=0;i<k;i++){
            sum += double(nums[i])/k;
        }
        ans = max(ans, sum);
        for(int i=k;i<nums.size();i++){
            sum += double(nums[i] - nums[i-k]) / k;
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1,12,-5,-6,50,3};
    int k = 4;
    Solution s;
    double ans = s.findMaxAverage(nums, k);
    cout<<ans<<endl;
    
}