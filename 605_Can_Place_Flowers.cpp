#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i] + flowerbed[i-1] + flowerbed[i+1] > 0)    continue;
            
            flowerbed[i] = 1;
            n -= 1;
            if(n == 0)  return true;
        }
        if(n<=0)    return true;
        else    return false;
    }
};

int main(){
    vector<int> flowerbed{1, 0, 0, 0, 1};
    int n = 2;
    Solution s;
    bool ans = s.canPlaceFlowers(flowerbed, n);
    cout<<ans<<endl;
}