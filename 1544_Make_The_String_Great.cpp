#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans;
        stack<char> st;
        for(char c:s){
            if(st.empty() || abs(int(c) - int(st.top())) != 32)  st.push(c);
            else    st.pop();
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int  main(){
    string s = "leEeetcode";
    Solution sol;
    string ans = sol.makeGood(s);
    cout<<ans<<endl;
}