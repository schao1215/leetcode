#include <iostream>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> poss(n, 0);
        for(vector<int> vec:trust){
            poss[vec[0] - 1] = -1;
            if(poss[vec[1] - 1] != -1)
                poss[vec[1] - 1] += 1;
        }
        for(int i=0;i<n;i++)
            if(poss[i] == n-1)  return i+1;
        
        return -1;
    }
};

int main(){
    int n=3;
    vector<vector<int>> trust{{1, 3},{2, 3},{3, 1}};
    Solution s;
    int ans = s.findJudge(n, trust);
    cout<<ans<<endl;
}