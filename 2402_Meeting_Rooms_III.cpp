#include <iostream>
using namespace std;

class Solution {
public:
    // static bool cmp(vector<int> v1, vector<int> v2)    {return (v1[0] < v2[0]);}
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long int> last(n, 0);
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        for(vector<int> time_pair:meetings){
            // cout<<"###"<<endl;
            int tmp_idx = 0;
            for(int i=0;i<n;i++){
                if(last[i] <= time_pair[0]){
                    tmp_idx = i;
                    break;
                }
                if(last[i] < last[tmp_idx])   tmp_idx = i;
            }

            if(last[tmp_idx] < time_pair[0])
                last[tmp_idx] = time_pair[1];
            else
                last[tmp_idx] += (time_pair[1] - time_pair[0]);
            cnt[tmp_idx] += 1;
            // cout<<last[0]<<" "<<last[1]<<endl;
        }
        int ans = 0;
        int tmp = 0;
        for(int i=0;i<n;i++){
            if(cnt[i] > tmp){ans = i;   tmp = cnt[i];}
        }
        return ans;
    }
};


int main(){
    int n = 4;
    vector<vector<int>> meetings{{18,19},{3,12},{17,19},{2,13}, {7, 10}};
    Solution s;
    int ans = s.mostBooked(n, meetings);
    cout<<ans<<endl;
}