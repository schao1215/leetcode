#include <iostream>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int rec_max = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size());
        for(int i=0;i<candies.size();i++){
            if(candies[i] + extraCandies >= rec_max)    ans[i] = true;
            else    ans[i] = false;
        }
        return ans;
    }
};

int main(){
    vector<int> candies{2,3,5,1,3};
    int extraCandies = 3;
    Solution s;
    vector<bool> ans = s.kidsWithCandies(candies, extraCandies);
    for(bool x:ans) cout<<x<<" ";
}