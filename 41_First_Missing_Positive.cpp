#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // cyclic sort approach
        // since that three are only nums.size() elements, the maximum possible answer will be nums.size() + 1
        // If there exist duplicate numbers, we will find the maximum number will be reduced by 1
        // We may place all the numbers that doesn't fit the requirement to the tail of the array
        int tail = nums.size();
        for(int i=0;i<tail;i++){
            while(nums[i] != i+1 && i<tail){
                if(nums[i] >= tail+1 || nums[i] <= 0 || nums[nums[i]-1] == nums[i]){
                    swap(nums[i], nums[tail-1]);
                    tail -= 1;
                }
                else{
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        for(int i=0;i<tail;i++){
            if(nums[i] != i+1)  return i+1;
        }
        return tail+1;
    }
};

int main(){
    vector<int> nums{3, 4, 2, 1};
    Solution s;
    int ans = s.firstMissingPositive(nums);
    cout<<ans<<endl;
}