#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<=0)    return false;
        // if((n & n-1)) return false;
        // else    return true;
        return (n>0) && !(n & n-1);
    }
};

int main(){
    int n = 16;
    Solution s;
    bool ans = s.isPowerOfTwo(n);
    cout<<ans;
}