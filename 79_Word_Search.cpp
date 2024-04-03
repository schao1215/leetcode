#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> _board;
    int m,n;
    string _word;
    vector<pair<int, int>> displace{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValid(int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0)  return false;
        return true;
    }

    bool dfs(int i, int j, int pos){
        if(pos == _word.size()) return true;
        if(!isValid(i, j) || _board[i][j] != _word[pos] || _board[i][j] == '0')    return false;
        char tmp = _board[i][j];
        _board[i][j] = '0';
        for(auto p:displace){
            if(dfs(i+p.first, j+p.second, pos+1))   return true;
        }
        _board[i][j] = tmp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        _board = board;
        m = _board.size(), n = _board[0].size();
        _word = word;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(dfs(i, j, 0))    return true;}
        return false;
    }
};


int main(){
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    Solution s;
    for(auto vec:board) {for(auto ele:vec)   cout<<ele<<" "; cout<<endl;}
    bool ans = s.exist(board, word);
    cout<<ans<<endl;
}