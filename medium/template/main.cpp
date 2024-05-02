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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *oriHead = head;
        ListNode *l = new ListNode(0, head);

        int i = 0;
        while(head != nullptr){
            if(i >= n) l = l->next;
            
            i++;
            head = head->next;
        }

        if(i == 1) return nullptr;
        else if(l->next == oriHead) return oriHead->next;
        else {            
            l->next = l->next->next;
            return oriHead;
        }

    }
};
