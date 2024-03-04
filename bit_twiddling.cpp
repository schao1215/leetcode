#include <iostream>
#include <bitset>

#define ITOB(X) bitset<8>(X).to_string()
using namespace std;

int main(){
    int x = -20;
    int y = x >> 1;
    bool cond = false;
    cout<<ITOB(-cond)<<endl;
    // cout<<(x>>1)<<endl;

    string x_b = ITOB(x);
    string y_b = ITOB(y);
    cout<<x<<" "<<y<<endl;
    cout<<x_b<<endl<<y_b<<endl;

    int res = (x^y);
    // cout<<ITOB(res)<<" "<<res<<endl;

    // cout<< ((y + (y>>31)) ^ (y>>31)) <<endl;
}