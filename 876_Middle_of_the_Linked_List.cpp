#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while(true){
            if(fast->next){
                fast = fast->next;
                head = head->next;
            }
            else    return head;
            if(fast->next){
                fast = fast->next;
            }
            else    return head;
        }
    }
};