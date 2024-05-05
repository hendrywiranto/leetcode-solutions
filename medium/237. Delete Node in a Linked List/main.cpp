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
    void deleteNode(ListNode* node) {
        ListNode *prev = node;
        node = node->next;
        prev->val = node->val;

        while(node->next != nullptr){
            node->val = node->next->val;
            node = node->next;
            prev = prev->next;
        }        

        prev->next = nullptr;

        return;
    }
};
