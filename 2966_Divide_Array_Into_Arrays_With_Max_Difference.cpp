#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n = 6;

class Solution {
public:
    vector<vector<int> > divideArray(vector<int>& nums, int k) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n/3;i++){
            vector<int> v;
            for(int j=0;j<3;j++){
                v.push_back(nums[i*3+j]);
            }
            if((v[2]-v[0]) > k){
                vector<vector<int> > empty;
                return empty;
            }
            ans.push_back(v);
        }

        return ans;
    }
};

int main(){
    Solution solution;

    // Sample input
    vector<int> nums = {5, 2, 8, 3, 1, 7};
    int k = 3;

    // Call the divideArray function
    vector<vector<int> > result = solution.divideArray(nums, k);

    // Print the result
    cout << "Result:\n";
    for (int i=0;i<n/3;i++) {
        for (int j=0;j<3;j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}