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
private:
    ListNode* reverse(ListNode* head){
        ListNode *tmp = nullptr, *next = nullptr;
        while(head != nullptr){
            next = head->next;
            head->next = tmp;
            tmp = head;
            head = next;
        }

        return tmp;
    }

public:
    ListNode* removeNodes(ListNode* head) {        
        ListNode *rev = reverse(head);
        ListNode *oriRev = rev;
        int maxVal = rev->val;        
        
        while(rev != nullptr && rev->next != nullptr){
            if(rev->next->val < maxVal){
                rev->next = rev->next->next;
            } else {                
                rev = rev->next;
                maxVal = max(maxVal, rev->val);
            }
        }
        return reverse(oriRev);
    }
};
