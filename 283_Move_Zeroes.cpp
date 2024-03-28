#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = INT_MAX, r = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                l = i;
                break;
            }
        }
        for(int i=l;i<nums.size();i++){
            if(nums[i] != 0){
                r = i;
                break;
            }
        }
        if(l > r) return;
        cout<<l<<" "<<r<<endl;
        while(r < nums.size()){
            if(nums[r] == 0)    r++;
            else if(nums[l] != 0)   l++;
            else{
                swap(nums[r++], nums[l++]);
            }
            // cout<<"#"<<endl;
        }
    }
};

int main(){
    vector<int> nums{1};
    Solution s;
    s.moveZeroes(nums);
    for(int ele:nums)   cout<<ele<<" ";
    cout<<endl;
}