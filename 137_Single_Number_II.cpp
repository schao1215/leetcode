#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int l_cnt = 0;
        int r_cnt = 0;
        int center = nums[0];
        int l_bound = INT_MIN;
        int r_bound = INT_MAX;
        while(true){
            for(int i=0;i<nums.size();i++){
                if(l_cnt == 1){
                    if(nums[i] < r_bound)
                        return nums[i];
                }
                else if(r_cnt == 1){
                    if(nums[i] > l_bound)
                        return nums[i];
                }
                else
                    if(nums[i] > l_bound && nums[i] < r_bound){
                        center = nums[i];
                        break;
                    }
            }
            // cout<<center<<endl;
            l_cnt = 0;
            r_cnt = 0;

            for(int i=0;i<nums.size();i++){
                if(nums[i] < center)
                    l_cnt += 1;
                else if(nums[i] > center)
                    r_cnt += 1;
                else
                    continue;
            }
            if(l_cnt % 3 == 0 && r_cnt % 3 == 0)
                return center;
            else if(l_cnt % 3 == 0)
                l_bound = center;
            else
                r_bound = center;
            
            
            // cout<<l_cnt<<" "<<r_cnt<<endl;
        }
    }
};

int main(){
    vector <int> nums{43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
    Solution s;
    int ans = s.singleNumber(nums);
    cout<<ans<<endl;
}