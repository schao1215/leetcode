#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        // vector<vector<bool>> is_pal;
        // vector<bool> tmp(len, -1);
        int cnt = 0;
        for(int center = 0;center < len;center++){
            int shift = 0;
            // odd
            while((center - shift) >=0 && (center + shift) <= len-1){
                if(s[center - shift] == s[center + shift]){
                    cnt += 1;
                    shift += 1;
                }
                else    break;
                // cout<<cnt<<endl;
            }

            // even
            shift = 0;
            while((center - shift) >=0 && (center + shift + 1) <= len-1){
                if(s[center - shift] == s[center + shift + 1]){
                    cnt += 1;
                    shift += 1;
                }
                else    break;
            }
        }
        return cnt;
    }
};

int main(){
    string str = "abcba";
    Solution s;
    int ans = s.countSubstrings(str);
    cout<<ans<<endl;

}