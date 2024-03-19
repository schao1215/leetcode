// If either the space is small or the number of max count element is large 
// will help to fill the whole sequence.

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        // priority_queue<char, int> pq;
        unordered_map<char, int> char_count;
        int max_ = 0;
        int max_count = 0;
        for(char ch:tasks){
            char_count[ch] ++;
            if(char_count[ch] > max_){
                max_ = char_count[ch];
                max_count = 1;
            }
            else if(char_count[ch] == max_)
                max_count ++;
            else    continue;
        }
        // sort(char_count.begin(), char_count.end(), greater<int>());
        for(int i=0;i<char_count.size();i++){
            if(char_count[i] == max_)   max_count++;
            else    break;
        }
        int ans = max(((n+1) * (max_-1) + max_count), size);

        // cout<<max_<<" "<<max_count<<endl;

        // for(auto ele:char_count)    cout<<ele<<" ";
        return ans;
    }
};

int main(){
    vector<char> tasks{'A','A', 'A', 'B','B', 'B', 'C'};
    int n = 2;
    Solution s;
    int ans = s.leastInterval(tasks, n);
    cout<<ans<<endl;
}