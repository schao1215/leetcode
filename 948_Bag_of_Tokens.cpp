#include <iostream>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int size = tokens.size();
        int l = 0, r = size - 1;
        int score = 0;
        int max_score = 0;
        while(l <= r){
            if(tokens[l] <= power){
                power -= tokens[l];
                l++;
                score += 1;
            }
            else{
                if(score == 0)  break;
                power += tokens[r];
                r -= 1;
                score -= 1;
            }
            max_score = max(max_score, score);
        }


        return max_score;
    }
};

int main(){
    vector<int> tokens{100, 200, 300, 400};
    int power = 200;
    Solution s;
    int ans = s.bagOfTokensScore(tokens, power);
    cout<<ans<<endl;
}