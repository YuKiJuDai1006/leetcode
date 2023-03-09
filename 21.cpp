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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int n1 = 0, n2 = 0, n = 0;
        int len1 = 0, len2 = 0;
        ListNode* h = list1;
        while(h){
            len1++;
            h = h->next;
        }
        h = list2;
        while(h){
            len2++;
            h = h->next;
        }

        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* res = new ListNode();
        ListNode* go = res;
        while(h1 && h2){
            if(h1->val <= h2->val){
                go->next = h1;
                go = go->next;
                h1 = h1->next;
            }
            else{
                go->next = h2;
                go = go->next;
                h2 = h2->next;
            }
        }
        if(h2){
            while(h2){
                go->next = h2;
                go = go->next;
                h2 = h2->next;
            }
        }
        if(h1){
            while(h1){
                go->next = h1;
                go = go->next;
                h1 = h1->next;
            }
        }
        return res->next;
    }
};