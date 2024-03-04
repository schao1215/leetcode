#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<pair<int, char>> vec;
        for(int i=0;i<s.size();i++){
            if(vowel.count(s[i]))   vec.push_back(make_pair(i, s[i]));
        }
        for(int i=0;i<vec.size();i++){
            s[vec[i].first] = vec[vec.size() - 1 - i].second;
        }
        return s;
    }
};

int main(){
    string s = "leetcode";
    Solution sol;
    string ans = sol.reverseVowels(s);
    cout<<ans;
}