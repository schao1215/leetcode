#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums{123456789, 23456789, 3456789, 456789, 56789, 6789, 789, 89, 9};
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(nums[i] >= 1){
                if(nums[i] >= low && nums[i] <= high){
                    ans.push_back(nums[i]);   
                }
                nums[i] /= 10;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    int low, high;
    low = 100;
    high = 13000;
    Solution s;
    vector<int> ans = s.sequentialDigits(low, high);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}