#include<iostream>
using namespace std;


class Solution {
public:
    int pivotInteger(int n) {
        // 1+2+...+n = n(n+1)/2=x(x+1)
        // 1+2+...+x = x(x+1)/2
        int sum = n*(n+1)/2;
        // cout<<sum<<endl;
        for(int i=1;i<=n;i++){
            if(i * (i+1) == (sum + i))    return i;    
        }
        return -1;
    }
};

int main(){
    int n = 8;
    Solution s;
    int ans = s.pivotInteger(n);
    cout<<ans<<endl;
}