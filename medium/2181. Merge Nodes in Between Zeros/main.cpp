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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        int total = 0;
        ListNode *ans = new ListNode();
        ListNode *ansHead = ans;
        
        while(head != nullptr){
            if(head->val == 0){
                ansHead->next = new ListNode(total);
                ansHead = ansHead->next;
                total = 0;
            }
            else {
                total += head->val;
            }

            head = head->next;
        }

        return ans->next;
    }
};
