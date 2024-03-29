#include <iostream>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i=0;i<t.size() && idx < s.size();i++){
            if(t[i] == s[idx])  idx++;
        }
        if(idx == s.size())   return true;
        else    return false;
    }
};


int main(){
    string s = "abc";
    string t = "ahbgdc";
    Solution sol;
    bool ans = sol.isSubsequence(s, t);
    cout<<ans;
}