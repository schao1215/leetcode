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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode *tmp = head;
        while(tmp){
            size++;
            tmp = tmp->next;
        }
        int middle;
        size/2 % 1 ? middle = size/2 + 1 : middle = size/2 ;

        for(int i=0;i<middle;i++){
            tmp = tmp->next;
        }

        ListNode *prev_node = nullptr;
        ListNode *node = tmp;
        ListNode *next_node;
        while(node){
            cout<<node->val<<endl;
            next_node = node->next;
            node->next = prev_node;
            prev_node = node;
            node = next_node;
        }
        tmp = head;

        //cmp
        while(tmp && prev_node){
            if(tmp->val != prev_node->val)  return false;
            else{
                tmp = tmp->next;
                prev_node = prev_node->next;
            }
        }
        return true;
    }
};