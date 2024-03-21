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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev_node = nullptr;
        ListNode *node = head;
        ListNode *next_node;
        while(node){
            cout<<node->val<<endl;
            next_node = node->next;
            node->next = prev_node;
            prev_node = node;
            node = next_node;
        }
        return prev_node;
    }
};
