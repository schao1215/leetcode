#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int mem = 1;
        for(int i=1;i<chars.size();i++){
            if(chars[i] != chars[i-1]){
                // the char itself
                chars[ans] = chars[i-1];
                ans += 1;
                if(mem != 1){
                    int digit = (int)(log10(mem)+1);
                    // cout<<mem<<endl;
                    // cout<<"digit="<<digit<<endl;
                    for(int i=digit-1;i>=0;i--){
                        // cout<<mem<<endl;
                        int x = (int)pow(10, i);
                        chars[ans] = char(mem/x + 48);
                        ans += 1;
                        // cout<<"$$"<<chars[ans]<<endl;
                        mem -= mem/x * x;
                    }
                }
                mem = 1;
            }
            else    mem += 1;
        }
        // cout<<"###"<<endl;
        chars[ans] = chars[chars.size()-1];
        ans += 1;
        if(mem != 1){
            int digit = (int)(log10(mem)+1);
            for(int i=digit-1;i>=0;i--){
                // cout<<mem<<endl;
                int x = (int)pow(10, i);
                chars[ans] = char(mem/x + 48);
                ans += 1;
                mem -= mem/x * x;
            }
        }
        return ans;
    }
};

int main(){
    char carr[] = {'a','b','b','b','b','b','b','b','b','b','b','b','c','c'};
    vector<char> chars(carr, carr + sizeof(carr) / sizeof(carr[0]));
    Solution s;
    int ans = s.compress(chars);
    cout<<ans<<endl;
    for(auto x:chars)   cout<<x<<" ";
    // cout<<endl;
}