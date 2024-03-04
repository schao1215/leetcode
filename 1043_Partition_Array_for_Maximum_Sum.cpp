#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector <int> dp(k);
        int range_max = 0;
        int mem;
        for(int i=0;i<arr.size();i++){
            // dp[i%k] = 0;
            if(i < k){
                // range_max = *max_element(arr.begin(), arr.begin()+i+1);
                range_max = max(range_max, *(arr.begin()+i));
                dp[i%k] = range_max * (i+1);
            }
            else{
                range_max = 0;
                mem = dp[i%k];
                // cout<<"mem = "<<mem<<endl;
                // cout<<*(arr.begin()+1)<<"#####"<<endl;
                for(int j=k;j>=1;j--){
                    // i = 3, j = 3, k = 3
                    range_max = max(*(arr.begin()+i-(k-j)), range_max);
                    mem = max(mem, dp[(i-(k-j+1))%k] + range_max * (k-j+1));
                }
                dp[i%k] = mem;
            }
            // for(int x=0;x<k;x++){
            //     cout<<dp[x]<<" ";
            // }
            // cout<<endl;
            
        }
        // cout<<"###"<<endl;
        return dp[(arr.size()-1)%k];
    }
};



int main(){
    vector <int> arr{1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    Solution s;
    int ans = s.maxSumAfterPartitioning(arr, k);
    cout<<ans<<endl;
}