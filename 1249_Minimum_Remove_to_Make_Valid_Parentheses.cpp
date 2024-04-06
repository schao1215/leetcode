#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<bool, int>> st;  // (left: 0/right: 1, index);
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') st.push(make_pair(0, i));
            else if(s[i] == ')'){
                if(st.empty() || st.top().first)    st.push(make_pair(1, i));
                else    st.pop();
            }
            else    continue;
        }
        while(!st.empty()){
            s.erase(s.begin() + st.top().second);
            st.pop();
        }
        return s;
    }
};

int main(){
    string s = "a)b(c)d";
    Solution sol;
    string ans = sol.minRemoveToMakeValid(s);
    cout<<ans<<endl;
}