#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l=0, r = height.size()-1;
        while(l != r){
            ans = max((r - l) * min(height[l], height[r]), ans);
            if(height[l] < height[r]){
                int tmp = l;
                do{
                    l++;
                }while(l != r && height[l] < height[tmp]);
            }
            else{
                int tmp = r;
                do{
                    r--;
                }while(l != r && height[r] < height[tmp]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution s;
    int ans = s.maxArea(height);
    cout<<ans<<endl;
}