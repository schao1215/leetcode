#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0, last = -1;
        vector<int> ans;
        while(i != nums1.size() && j != nums2.size()){
            // cout<<i<<" "<<j<<endl;
            if(nums1[i] < nums2[j] || 
                    nums1[i] == last) i++;
            else if(nums1[i] > nums2[j] || 
                    nums2[j] == last) j++;
            else if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                last = nums1[i];
                i++;
                j++;
            }
            else    break;
            

        }
        return ans;
    }
};

int main(){
    vector<int> num1{4, 9, 5};
    vector<int> num2{9, 4, 9, 8, 4};
    Solution s;
    vector<int> ans = s.intersection(num1, num2);
    for(auto x: ans)    cout<<x<<" ";
    cout<<endl;
}