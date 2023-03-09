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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);
        int step = 0;
        if(lenA > lenB){
            while(step < lenA-lenB){
                headA = headA->next;
                ++step;
            }
        }
        else{
            while(step < lenB-lenA){
                headB = headB->next;
                ++step;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int len(ListNode* head){
        int res = 0;
        while(head){
            ++res;
            head = head->next;
        }
        return res;
    }
};