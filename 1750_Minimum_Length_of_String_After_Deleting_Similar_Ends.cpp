#include <iostream>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int size = s.size();
        int l = 0, r = size - 1;
        char last = 'x';
        while(l <= r){
            // cout<<l<<" "<<r<<endl;
            if(s[l] == s[r] && l!= r){
                last = s[l];
                l += 1;
                r -= 1;
                size -= 2;
            }
            else if(s[l] == last) {l+=1; size-=1;}
            else if(s[r] == last) {r-=1; size-=1;}
            else    break;
        }
        return size;
    }
};

int main(){
    string s = "cabaabac";
    Solution sol;
    int ans = sol.minimumLength(s);
    cout<<ans<<endl;

}