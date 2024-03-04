#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        int tmp = 1;
        for(int i=0;i<31;i++){
            if(left < tmp && right >= tmp)   return 0;
            else    tmp *= 2;
            if(left < tmp && right < tmp)   break;
        }

        int sub = right - left + 1;
        int mem = 0;
        while(sub != 1){
            left = left >> 1;
            right = right >> 1;
            (sub%2 == 1) ? sub = sub/2 + 1 : sub = sub/2;
            mem += 1;
            cout<<left<<" "<<right<<endl;
        }
        left = left & right;
        // cout<<left<<endl;
        for(int i=0;i<mem;i++) {
            left = left << 1;
            
        }
        return left;
    }
};

int main(){
    int left = 2147483646;
    int right = 2147483647;
    Solution s;
    int ans = s.rangeBitwiseAnd(left, right);
    cout<<ans<<endl;
}