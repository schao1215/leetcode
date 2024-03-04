#include <iostream>
#include <set>
#include <queue>

using namespace std;
#define int2(X, Y) make_pair(X, Y)

class Solution {
public:

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& meet:meetings){
            adj[meet[0]].push_back(int2(meet[2], meet[1]));
            adj[meet[1]].push_back(int2(meet[2], meet[0]));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(int2(0, 0));
        pq.push(int2(0, firstPerson));
        
        vector<int> known_time(n, INT_MAX);
        vector<int> ans;

        while(!pq.empty()){
            auto [s, x] = pq.top();
            pq.pop();
            if(known_time[x] != INT_MAX) continue;
            ans.push_back(x);
            known_time[x] = s;
            for(auto& p:adj[x]){
                auto [t, y] = p;
                if(t<s || known_time[y] != INT_MAX) continue;
                    pq.push(p);
            }
        }
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> meetings{{0,2,1},{1,3,1},{4,5,1}};
    int firstPerson = 1;
    Solution s;
    vector<int> ans = s.findAllPeople(n, meetings, firstPerson);
    for(int x:ans)  cout<<x<<" ";
    cout<<endl;
}