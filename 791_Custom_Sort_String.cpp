#include <iostream>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> ump;
        for(auto ele : s) ump[ele]++;
        string ans;
        for(auto ele : order){
            for(int i=0;i<ump[ele];i++) ans += ele ;
            ump[ele] = -1;
        }
        cout<<ans<<endl;
        for(auto ele : s){
            if(ump[ele] > 0)
                ans += ele ;
        }
        return ans;

    }
};

int main(){
    string order = "hucw";
    string s = "utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh";
    Solution sol;
    string ans = sol.customSortString(order, s);
    cout<<ans<<endl;
}