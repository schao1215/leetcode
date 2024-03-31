#include <iostream>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int r = 0;
        int min_head = -1, last_min = -1;
        int max_head = -1, last_max = -1;
        long long ans = 0;

        bool last = false;  // true = max, false = min

        while(r < nums.size()){
            if(nums[r] < minK || nums[r] > maxK){
                //reset
                min_head = r;
                max_head = r;
                last_min = -1;
                last_max = -1;
                r++;
                continue;
            }

            if(nums[r] == minK) {last_min = r;  last = false;}
            if(nums[r] == maxK) {last_max = r;  last = true;}


            if(last_min >= 0 && last_max >= 0){
                if(last)
                    ans += last_min - min_head;
                else
                    ans += last_max - max_head;
            }

            r++;
        }

        return ans;
    }
};

int main(){
    vector<int> nums{35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};
    int minK = 35054, maxK = 945315;
    Solution s;
    long long ans = s.countSubarrays(nums, minK, maxK);
    cout<<ans<<endl;
}