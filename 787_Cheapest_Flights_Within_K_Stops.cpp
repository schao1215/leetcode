#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight:flights)    adj[flight[1]].push_back(make_pair(flight[0], flight[2]));
        queue<pair<int, int>> q;
        for(auto flight:adj[dst]) q.push(flight);
        q.push(make_pair(-1, -1));
        int length = -1;
        int min_price = INT_MAX;
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            // cout<<tmp.first<<"   @@@"<<endl;
            if(tmp.first == -1){
                q.push(make_pair(-1, -1));
                // cout<<"####"<<endl;
                length += 1;
                if(length == k) break;
                q.pop();
                continue;
            }
            for(auto flight:adj[tmp.first]){
                if(flight.second + tmp.second < min_price)
                    q.push(make_pair(flight.first, flight.second + tmp.second));
                // cout<<"flight: "<<flight.first<<" "<<flight.second<<endl;
            }
            if(tmp.first == src){
                min_price = min(min_price, tmp.second);
            }
            q.pop();
            // cout<<tmp.first<<" "<<tmp.second<<endl<<"$$"<<endl;
            // cout<<q.front().first<<" "<<q.front().second<<endl;
        }
        if(min_price == INT_MAX)    return -1;
        else    return min_price;

    }
};

int main(){
    int n = 3;
    vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};
    int src = 0, dst = 2;
    int k = 0;
    Solution s;
    int ans = s.findCheapestPrice(n, flights, src, dst, k);
    cout<<ans<<endl;
}