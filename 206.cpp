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
    ListNode* reverseList(ListNode* head) {
        ListNode* h = head;
        ListNode* u = nullptr;
        ListNode* v = nullptr;
        while(h){
            u = h->next;
            h->next = v;
            v = h;
            h = u;
        }
        return v;
    }
};