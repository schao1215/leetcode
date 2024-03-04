#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 1;
        ListNode* node = head;
        while(node->next){
            node = node->next;
            sz++;
        }
        if(sz == 1) return head->next;
        if(sz == n) return head->next;
        node = head;
        for(int i=0;i<sz - n - 1;i++){
            // cout<<node->val<<" ";
            node = node->next;
        }
        // cout<<" "<<node->val<<endl;
        // cout<<" "<<node->next->val<<endl;
        // cout<<node->next->next->val<<endl;
        node->next = node->next->next;
        // cout<<" "<<node->val<<endl;
        // cout<<" "<<node->next->val<<endl;
        return head;
    }
};

ListNode* setUpLinkedList(vector<int>& nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode* node = head;
    for(int i=0;i<nums.size()-1;i++){
        node->next = new ListNode(nums[i+1]);
        node = node->next;
    }
    return head;
}

int main(){
    vector<int> nums{1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = setUpLinkedList(nums);
    Solution s;
    head = s.removeNthFromEnd(head, n);
    ListNode* node = head;
    while(node){
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
}