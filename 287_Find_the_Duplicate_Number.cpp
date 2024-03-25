#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    // n = 4
    vector<int> nums{3, 2, 1, 4, 3};
    Solution s;
    int ans = s.findDuplicate(nums);
    cout<<ans<<endl;
}