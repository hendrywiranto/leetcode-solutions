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
    ListNode* middleNode(ListNode* head) {
        int midIndex = 0;
        int count = 0;
        ListNode *mid = head;
        while(head != nullptr){
            count++;
            if(midIndex < count / 2){
                mid = mid->next;
                midIndex = count / 2;
            }

            head = head->next;
        }

        return mid;
    }
};
