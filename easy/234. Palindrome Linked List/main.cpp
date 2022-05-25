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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        int n = 0;

        // find length
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }

        // find where the second half start
        n = (n%2 == 1) ? (n/2)+1 : n/2;
        ListNode* clone = head;
        for(int i=0;i<n;i++){
            clone = clone->next;
        }

        // reverse 2nd half
        ListNode *temp, *last = nullptr;
        while(clone != nullptr){
            temp = clone->next;
            clone->next = last;
            last = clone;
            clone = temp;
        }

        // compare 1st half with reversed 2nd half
        while(last != nullptr){
            if(last->val != head->val) return false;
            last = last->next;
            head = head->next;
        }

        return true;
    }
};
