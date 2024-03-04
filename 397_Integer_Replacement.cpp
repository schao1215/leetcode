#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int step = 0;
        while(n != 1){
            cout<<n<<endl;
            step += 1;
            if(n%2 == 0){
                n /= 2;
            }
            else{
                if(n%4 == 3)    n += 1;
                else    n -= 1;
            }
        }
        return step;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.integerReplacement(n);

}