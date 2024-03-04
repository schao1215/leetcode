#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length = min(word1.size(), word2.size());
        string ans;
        for(int i=0;i<length;i++){
            ans += word1[i];
            ans += word2[i];
        }
        if(word1.size() > length)
            for(int i=length;i<word1.size();i++)    ans += word1[i];
        if(word2.size() > length)
            for(int i=length;i<word2.size();i++)    ans += word2[i];
        
        return ans;
        
    }
};

int main(){
    string word1 = "abcd";
    string word2 = "pr";
    Solution s;
    string ans = s.mergeAlternately(word1, word2);
    cout<<ans<<endl;
}