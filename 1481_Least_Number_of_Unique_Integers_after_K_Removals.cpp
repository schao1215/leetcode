#include <iostream>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> num_count;
        vector<int> count_count;
        int vec_size = 0;
        for(int num:arr){
            if(!num_count.count(num))   num_count[num] = 1;
            else    num_count[num] += 1;

            if(num_count[num] > vec_size){
                count_count.push_back(1);
                if(vec_size != 0)
                    count_count[vec_size - 1] -= 1;
                vec_size += 1;
            }
            else{
                count_count[num_count[num] - 1] += 1;
                if(num_count[num] > 1)  count_count[num_count[num] - 2] -= 1;
            }
        }
        int idx = 0;
        int minus = 0;
        
        while(k > 0){
            if(count_count[idx] * (idx+1) >= k){
                minus = k / (idx+1);
                break;
            }
            else{
                k -= count_count[idx] * (idx+1);
                idx += 1;
            }
            // cout<<k<<endl;
        }

        int ans = -minus;
        for(int i=idx;i<count_count.size();i++){
            ans += count_count[i];
            // cout<<ans<<endl;
        }
        // cout<<idx<<" "<<minus<<endl;
        // for(int num:count_count)    cout<<num<<endl;
        return ans;
    }
};

int main(){
    vector<int> arr{13,22,100,22,5,62,13,24,81,15,99,14,20,2,61,10,40,47,33,7,38,47,92,31,15,40,73,48,24,55,81,63,37,23,59,78,5,50,10,51,67,9,18,78,89,40,71,7,32,67,6,34,69,59,19,39,96,64,81,96,64,5,82,59,29,93,42,72,38,60,82,40,97,91,4,22,85,80,33,51,10,21,54,91,2,94,38,38,19,75,37,7,76,7,27,8,76,11,25,5};
    int k = 78;
    Solution s;
    int ans = s.findLeastNumOfUniqueInts(arr, k);
    cout<<ans<<endl;
}