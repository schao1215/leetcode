#include<iostream>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r;
        int ans = 0;
        for(r=0;r<nums.size();r++)  if(nums[r] >= k)    break;
        r--;

        while(l < r){
            int tmp = nums[l] + nums[r];
            if(tmp == k)    l++, r--, ans++;
            else if(tmp < k)    l++;
            else    r--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4, 9};
    int k = 5;
    Solution s;
    int ans = s.maxOperations(nums, k);
    cout<<ans<<endl;
}