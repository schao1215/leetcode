#include <iostream>
#include <queue>

#define p(X, Y) make_pair(X, Y)

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // int will be the level
    queue<pair<TreeNode*, int>> q;
    bool isEvenOddTree(TreeNode* root) {
        q.push(p(root, 0));
        int lastInt = root->val;
        int lastLevel = 0;
        while(!q.empty()){
            auto& mem = q.front();
            if(mem.first->left)    q.push(p(mem.first->left, mem.second+1));
            if(mem.first->right)    q.push(p(mem.first->right, mem.second+1));
            // odd level
            if(mem.second % 2){
                // all numbers should be even
                if(mem.first->val % 2) return false;
                // if the previous number is at the same level, the value shuoldn't be greater.
                if(mem.second == lastLevel && mem.first->val >= lastInt)    return false;

            }
            // even level
            else{
                // all nubmers should be odd
                if(!mem.first->val % 2) return false;
                if(mem.second == lastLevel && mem.first->val <= lastInt)    return false;
            }
            lastInt = mem.first->val;
            lastLevel = mem.second;
            q.pop();
        }
        return true;
    }
};