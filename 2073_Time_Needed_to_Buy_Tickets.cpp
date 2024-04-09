#include <iostream>
#include <queue>
using namespace std;
#define dtype pair<int,int>

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        priority_queue<dtype, vector<dtype>, greater<dtype>> pq;
        for(int i=0;i<tickets.size();i++)   pq.push(make_pair(tickets[i], i));
        int size = tickets.size();
        int ans = 0;
        int tmp = 0;
        int finished_before = 0;
        int finished = 0;
        while(!pq.empty()){
            auto p = pq.top();
            if(p.first == tickets[k]){
                ans += (size - finished) * (p.first - tmp - 1);
                ans += (k + 1 -finished_before);
                break;
                // do sth;
            }
            else if(p.first > tickets[k])   break;
            else{
                ans += (p.first - tmp) * (size - finished);
                finished += 1;
                tmp = p.first;
                if(p.second < k)    finished_before += 1;
                pq.pop();
            }
            cout<<p.first<<" "<<p.second<<" "<<ans<<endl;
        }        
        return ans;
    }
};

int main(){
    vector<int> tickets{84,49,5,24,70,77,87,8};
    int k = 3;
    Solution s;
    int ans = s.timeRequiredToBuy(tickets, k);
    cout<<ans<<endl;
}