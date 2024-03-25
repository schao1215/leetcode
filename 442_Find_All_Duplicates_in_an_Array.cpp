#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int tmp = i;
            while(nums[tmp] != tmp+1){
                for(int ele:nums)    cout<<ele<<" ";
                cout<<endl;
                if(nums[nums[tmp]-1] == nums[tmp]){
                    // ans.push_back(nums[tmp]);
                    break;
                }
                swap(nums[nums[tmp]-1], nums[tmp]);
                // nums[nums[tmp]-1] ^= nums[tmp];
                // nums[tmp] ^= nums[nums[tmp]-1];
                // nums[nums[tmp]-1] ^= nums[tmp];

            }
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i] != i+1)  ans.push_back(nums[i]);
        return ans;
    }
};

int main(){
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> ans = s.findDuplicates(nums);
    for(auto ele:ans)   cout<<ele<<" ";
    cout<<endl;
}