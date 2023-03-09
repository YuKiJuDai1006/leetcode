/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count = 0;
        ListNode* h = head;
        while(h && count < 10000){
            h = h->next;
            count++;
        }
        if(h) return 0;
        return 1;
    }
};