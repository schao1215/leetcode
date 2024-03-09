#include <iostream>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int idx_1 = 0, idx_2 = 0;
        while(idx_1 != nums1.size() && idx_2 != nums2.size()){
            if(nums1[idx_1] == nums2[idx_2])  return nums1[idx_1];
            nums1[idx_1] > nums2[idx_2] ? idx_2++ : idx_1++ ;
        }
        return -1;
    }
};