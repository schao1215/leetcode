#include <iostream>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l = 0;
        int r = 0;
        // for(r=1;r<s.size();r++)
        //     if(s[r] == '0') break;
        while(r < s.size()){
            if(s[l] == '0' && s[r] == '1'){
                swap(s[l], s[r]);
                l++;
                r++;
            }
            if(s[l] == '1'){
                l+=1;
                if(s[r] == '1') r+=1;
            }
            if(s[r] == '0') r+=1;
        }
        for(int i=s.size()-1;i>=0;i--)
            if(s[i] == '1'){
                swap(s[i], s[s.size() - 1]);
                break;
            }
        return s;
    }
};

int main(){
    string s = "11";
    Solution sol;
    string ans = sol.maximumOddBinaryNumber(s);
    cout<<ans<<endl;
}