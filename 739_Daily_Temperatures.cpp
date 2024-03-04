#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int arr_size = temperatures.size();
        vector<int> ans(arr_size);
        stack <int> idx;
        idx.push(0);
        
        for(int i=1;i<arr_size;i++){
            while(!idx.empty() && temperatures[i] > temperatures[idx.top()]){
                ans[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
            // cout<<i<<" "<<idx.size()<<endl;
        }
        while(!idx.empty()){
            ans[idx.top()] = 0;
            idx.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> temp {73,74,75,71,69,72,76,73}; // [1,1,4,2,1,1,0,0]
    Solution s;
    vector<int> ans = s.dailyTemperatures(temp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}