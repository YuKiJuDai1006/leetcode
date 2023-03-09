/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* h = head;
        while(h){
            ++len;
            h = h->next;
        }
        h = head;
        for(int i = 0; i < len/2; i++){
            h = h->next;
        }
        if(len % 2 == 1) h = h->next;
        ListNode* u = nullptr;
        ListNode* v = nullptr;
        while(h){
            u = h->next;
            h->next = v;
            v = h;
            h = u;
        }
        h = head;
        while(v){
            if(v->val != h->val) return 0;
            v = v->next;
            h = h->next;
        }
        return 1;

    }
};