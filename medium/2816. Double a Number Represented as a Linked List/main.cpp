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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = new ListNode(0, head);
        ListNode *oriCurr = curr;

        while(curr != nullptr && curr->next != nullptr){
            int d = curr->next->val * 2;
            if(d > 9){
                curr->val += d / 10;
                curr->next->val = d % 10;
            } else {
                curr->next->val = d % 10;
            }
            
            curr = curr->next;
        }

        if(oriCurr->val > 0) return oriCurr;
        else return oriCurr->next;
    }
};
