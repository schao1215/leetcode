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
    void reorderList(ListNode* head) {
        // reverse the back half
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next && slow->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        // reverse start from fast
        ListNode *prev_node = nullptr;
        ListNode *next_node;
        while(fast){
            next_node = fast->next;
            fast->next = prev_node;
            prev_node = fast;
            fast = next_node;
        }

        ListNode *tmp;
       

        while(prev_node){
            tmp = prev_node->next;
            prev_node->next = head->next;
            head->next = prev_node;
            prev_node = tmp;
            head = head->next->next;
        }
        head->next = prev_node;
    }
};