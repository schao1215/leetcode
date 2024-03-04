#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x = str1.size(), y = str2.size();
        int gcd;
        while(x != 0 && y != 0){
            if(x > y){
                x -= x/y * y;
                gcd = y;
            }
            else{
                y -= y/x * x;
                gcd = x;
            }
        }

        priority_queue<int> pq;
        for(int i=1;i<int(sqrt(gcd))+1;i++){
            if(gcd % i == 0){
                pq.push(i);
                pq.push(gcd/i);
            }
        }

        string ans;
        while(!pq.empty()){
            ans = ans.assign(str1, 0, pq.top());
            // cout<<ans<<endl;
            string tmp1, tmp2;
            for(int i=0;i<str1.size()/pq.top();i++)  tmp1 += ans;
            for(int i=0;i<str2.size()/pq.top();i++)  tmp2 += ans;
            if(tmp1 == str1 && tmp2 == str2)    return ans;
            else    pq.pop();
        }
        return "";
    }
};

int main(){
    string str1 = "ABCAB";
    string str2 = "ABC";
    Solution s;
    string ans =  s.gcdOfStrings(str1, str2);
    cout<<ans<<endl;
}