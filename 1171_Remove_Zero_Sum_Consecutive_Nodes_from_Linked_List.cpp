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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map <int, ListNode*> mp;
        ListNode* tmp = new ListNode(0, head);
        mp[0] = tmp;
        int cum = 0;
        while(head){
            cum += head->val;
            if(mp.find(cum) != mp.end()){
                ListNode *start = mp[cum];
                ListNode *temp = start;
                int pSum = cum;
                while(temp != head){
                    temp = temp->next;
                    pSum += temp->val;
                    if(temp != head)
                        mp.erase(pSum);
                }
                start->next = head->next;
            }
            else{
                mp[cum] = head;
            }
            head = head->next;
        }
        return tmp->next;
    }
};