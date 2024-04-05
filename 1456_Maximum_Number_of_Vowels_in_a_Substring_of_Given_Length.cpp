#include <iostream>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        for(int i=0;i<k;i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
        int ans = cnt;
        
        for(int i=k;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(){
    string s = "aeiou";
    int k = 2;
    Solution sol;
    int ans = sol.maxVowels(s, k);
    cout<<ans<<endl;
}