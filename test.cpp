#include <iostream>
#include <queue>

using namespace std;

// min heap

vector<int> vec;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(4);
    pq.push(2);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
}