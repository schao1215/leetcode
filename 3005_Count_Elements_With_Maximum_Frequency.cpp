#include <iostream>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> m;
        for(auto num:nums)  m[num] ? m[num]++ : m[num] = 1;
        int max_freq = 0;
        int ans = 0;
        for(auto& p:m){
            if(p.second == max_freq)    ans += max_freq;
            else if(p.second > max_freq){
                max_freq = p.second;
                ans = max_freq;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s;
    int ans = s.maxFrequencyElements(nums);
    cout<<ans<<endl;
}