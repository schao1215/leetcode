#include <iostream>
using namespace std;

    class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if(nums.size() == 1)    return nums;
            sort(nums.begin(), nums.end());
            vector<int> set_size(nums.size(), 0);
            vector<int> prev_index(nums.size());

            int max_size = 0;
            int max_set_last_index = 0;
            for(int i = 0;i<nums.size();i++){
                bool first = true;
                for(int j=0;j<i;j++){
                    if(nums[i]/2 < nums[j]) break;
                    if(nums[i] % nums[j] == 0){
                        first = false;
                        if(set_size[j] + 1 > set_size[i]){
                            set_size[i] = set_size[j] + 1;
                            prev_index[i] = j;
                            if(set_size[i] > max_size){
                                max_size = set_size[i];
                                max_set_last_index = i;
                            }
                        }
                    }
                }
                if(first)  {
                    set_size[i] = 1;
                    prev_index[i] = -1;
                    if(set_size[i] > max_size){
                        max_size = set_size[i];
                        max_set_last_index = i;
                    }
                }
            }

            // for(int i:set_size) cout<<i<<" ";
            // cout<<endl;
            // cout<<max_size<<endl;
            // cout<<max_set_last_index<<endl;

            vector<int> ans;
            // ans.push_back(nums[max_set_last_index]);
            int id = max_set_last_index;
            ans.push_back(nums[id]);
            while(prev_index[id] != -1){
                id = prev_index[id];
                ans.push_back(nums[id]);
            }

            // do{
            //     ans.push_back(nums[id]);
            //     id = prev_index[id];
            // }while(prev_index[id] != -1);
            // ans.push_back(nums[id]);



            return ans;

        }
    };

int main(){
    vector<int> nums{1,2, 4, 8, 3, 9, 27, 81};
    Solution s;
    vector<int> ans = s.largestDivisibleSubset(nums);
    for(int i:ans)  cout<<i<<" ";
    cout<<endl;
}