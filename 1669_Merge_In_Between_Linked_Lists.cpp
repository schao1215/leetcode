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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1;
        ListNode *start;
        ListNode *end;
        for(int i=1;i<=b;i++){
            if(i == a)  start = list1;
            if(i == b)  {
                end = list1->next->next;
                break;
            }
            list1 = list1->next;
        }
        start->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = end;
        return head;
    }
};