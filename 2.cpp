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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int fi = 0, si = 0;
        int mul = 1;
        ListNode* temp = l1;
        while(temp){
            int toAdd = temp->val * mul;
            fi += toAdd;
            temp = temp->next;
            mul *= 10;
        }
        mul = 1;
        temp = l2;
        while(temp){
            int toAdd = temp->val * mul;
            fi += toAdd;
            temp = temp->next;
            mul *= 10;
        }
        int res = fi + si;

        //
        ListNode *toRe = new ListNode();
        ListNode *to = toRe;
        while(res > 0){
            to -> val = res % 10;
            res /= 10;
            if(res > 0){
                ListNode *gg = new ListNode();
                to -> next = gg;
                to = gg;
            }
        }
        return toRe;
    }
};



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int in = 0;
    int res = 0;

    ListNode* toRe = new ListNode();
    ListNode* to = toRe;

    while(l1 || l2 || in){
        if(l1 && l2){
            res = l1->val + l2->val;
            res += in;
            if(res >= 10){
                res = res % 10;
                in = 1;
            }
            else in = 0;

            to->next = new ListNode(res);
            to = to->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        else {
            // L1
            if(l1){
                res = l1->val + in;
                if(res == 10){
                    res = 0;
                    in = 1;
                }
                else in = 0;
                l1 = l1->next;
                to->next = new ListNode(res);
                to = to->next;
            }
            // L2
            if(l2){
                res = l2->val + in;
                if(res == 10){
                    res = 0;
                    in = 1;
                }
                else in = 0;
                l2 = l2->next;
                to->next = new ListNode(res);
                to = to->next;
            }

            if(!l1 && !l2 && in) {
                to->next = new ListNode(1);
                to = to->next;
                in = 0;
            }
        }
    }

    return toRe->next;
}