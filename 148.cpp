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
    ListNode* sortList(ListNode* head) {
        vector<int> tab;
        ListNode* h = head;
        while(h){
            tab.push_back(h->val);
        }
        sort(tab.begin(), tab.end());
        h = head;
        int i = 0;
        while(h){
            h->val = tab[i];
            i++;
            h = h->next
        }
        return head;
    }
};0