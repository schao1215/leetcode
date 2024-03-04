#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void insertNode(TreeNode* root, int val){
    cout<<val<<endl;
    if(!root){
        root = new TreeNode(val);
    }
    else{
        if(!root->left) insertNode(root->left, val);
        if(!root->right) insertNode(root->right, val);
        else    insertNode(root->left, val);
    }
}

class Solution {
public:
    queue<TreeNode*> q;
    int mem = 0;
    int findBottomLeftValue(TreeNode* root) {
        q.push(root);
        while(!q.empty()){
            // cout<<pq.front()->val<<endl;
            if(q.front()->right) q.push(q.front()->right);
            if(q.front()->left) q.push(q.front()->left);
            if(!q.front()->right && !q.front()->left) mem = q.front()->val;
            q.pop();
        }
        return mem;
    }
};

int main(){
    vector<int> vec{2, 1, 3};
    // vector<TreeNode*> nodes;
    TreeNode* root = nullptr;
    for(const auto& num:vec){
        insertNode(root, num);
    }
    Solution s;
    int ans = s.findBottomLeftValue(root);
    cout<<ans<<endl;
}