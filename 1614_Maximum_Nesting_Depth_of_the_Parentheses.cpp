#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int tmp = 0;
        for(char ele:s){
            if(ele == '('){
                tmp += 1;
            }
            else if(ele == ')'){
                ans = max(ans, tmp);
                tmp -= 1;
            }
            else    continue;
        }
        return ans;
    }
};

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    Solution sol;
    int ans = sol.maxDepth(s);
    cout<<ans<<endl;
}