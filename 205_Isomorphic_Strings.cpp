#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp_re;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) == mp.end()){
                if(mp_re.find(t[i]) == mp.end()){
                    mp[s[i]] = t[i];
                    mp_re[t[i]] = s[i];
                }
                else    return false;
            }

            else{
                if(mp[s[i]] != t[i])    return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "egg";
    string t = "add";
    Solution sol;
    bool ans = sol.isIsomorphic(s, t);
    cout<<ans<<endl;
}