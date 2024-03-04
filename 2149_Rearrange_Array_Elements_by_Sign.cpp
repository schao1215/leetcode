#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        vector<int> ans;
        for(int num:nums){
            num > 0 ? pos.push(num) : neg.push(num) ;
            if(!pos.empty() && !neg.empty()){
                ans.push_back(pos.front());
                ans.push_back(neg.front());
                pos.pop();
                neg.pop();
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{3,1,-2,-5,2,-4};
    Solution s;
    vector<int> ans = s.rearrangeArray(nums);

    for(int i:ans)  cout<<i<<" ";
    cout<<endl;
}