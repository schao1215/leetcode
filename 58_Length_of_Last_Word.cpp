#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] != ' ')  ans++;

            else
                if(ans > 0) return ans;
        }
        return ans;
    }
};

int main(){
    string s = "   fly me   to   the moon  ";
    Solution sol;
    int ans = sol.lengthOfLastWord(s);
    cout<<ans<<endl;
}