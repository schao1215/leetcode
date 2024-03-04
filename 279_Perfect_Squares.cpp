#include <iostream>
#include <vector>
using namespace std;

// Set the vector dp to a large enough number
vector<int> dp(10007, INT_MAX);
class Solution {
public:
    int numSquares(int n) {
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j <= i;j++){
                // Applying bottom up dynamic programming
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};

int main(){
    int n = 56;
    Solution s;
    int ans = s.numSquares(n);
    int sum = 0;
    // for(int i:dp)   sum += i;
    // cout<<sum<<endl;
    cout<<ans<<endl;
}