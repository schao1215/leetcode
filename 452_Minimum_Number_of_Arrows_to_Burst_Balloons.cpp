#include <iostream>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1]; // 升序排列
        });
        int ans = 0;
        long long int end = LONG_MIN;
        for(int i=0;i<points.size();i++){
            if(end >= points[i][0]) continue;
            else{
                ans ++;
                end = points[i][1];
            }
        }
        // for(auto vec:points)    cout<<vec[0]<<" "<<vec[1]<<endl;
        return ans;
    }
};

int main(){
    vector<vector<int>> points{{1, 2}, {2, 7}, {4, 5}, {5, 6}};
    Solution s;
    int ans = s.findMinArrowShots(points);
    cout<<ans<<endl;
}