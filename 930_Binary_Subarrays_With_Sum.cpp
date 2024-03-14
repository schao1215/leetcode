#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // for(int i=1;i<nums.size();i++)  nums[i] += nums[i-1];
        if(count(nums.begin(), nums.end(), 1) < goal)   return 0;
        int count = 0;
        if(goal == 0){
            int tmp = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] == 1){
                    count += tmp * (tmp+1)/2;
                    tmp = 0;
                }
                else    tmp += 1;
            }
            count += tmp * (tmp+1)/2;
            return count;
        }

        int left, right = 0;
        int tmp = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == 1)    {left = i;  break;}
        for(right=left;right<nums.size();right++){
            tmp += nums[right];
            if(tmp == goal) break;
        }
        while(left < nums.size() && right < nums.size()){
            // cout<<left<<" "<<right<<" "<<tmp<<endl;
            if(tmp < goal || nums[right] != 1)  {right += 1;    tmp += nums[right];}
            else if(tmp > goal || nums[left] != 1) {tmp -= nums[left]; left += 1;}
            else{
                // cout<<"####"<<endl;
                int left_shift = 1, right_shift = 1;
                while(left - left_shift >= 0 && nums[left - left_shift] == 0)    left_shift += 1;
                while(right + right_shift <= nums.size()-1 && nums[right + right_shift] == 0)    right_shift += 1;
                // cout<<left_shift<<"   "<<right_shift<<endl;
                count += left_shift * right_shift;
                while(right < nums.size()){
                    right += 1;
                    if(nums[right] == 1){
                        tmp += nums[right];
                        break;
                    }
                }
            }

        }
        return count;
    }
};

int main(){
    vector<int> nums{0, 0, 1, 0, 1, 0};
    int goal = 2;
    Solution s;
    int ans = s.numSubarraysWithSum(nums, goal);
    cout<<ans<<endl;
}