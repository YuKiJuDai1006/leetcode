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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode* h = head;
        while(h->next){
            len++;
            h = h->next;
        }
        h = head;
        int go = len - n;
        if(go == 0){
            head = head->next;
            return head;
        }
        while(go > 1){
            h = h->next;
            go--;
        }
        h->next = h->next->next;
        return head;
    }

};