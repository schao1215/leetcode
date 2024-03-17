#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // if(intervals.size() == 0){
        //     intervals.push_back(newInterval);
        //     return intervals;
        // }
        int size = intervals.size();
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] > newInterval[0])   {intervals.insert(intervals.begin()+i, newInterval); break;}
            if(intervals[i][0] == newInterval[0])   {intervals[i][1] = max(intervals[i][1], newInterval[1]); break;}
        }
        if(size == intervals.size())    intervals.push_back(newInterval);
        // cout<<"###"<<endl;
        // for(auto vec:intervals){
        //     for(auto ele:vec)
        //         cout<<ele<<" ";
        //     cout<<endl;
        // }
        // cout<<"###"<<endl;

        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1] < intervals[i+1][0]) continue;
            else{
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
        }
        
        return intervals;
    }
};

int main(){
    vector<vector<int>> intervals{};
    vector<int> newInterval{2, 7};
    Solution s;
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(auto vec:ans){
        for(auto ele:vec)
            cout<<ele<<" ";
        cout<<endl;
    }
}