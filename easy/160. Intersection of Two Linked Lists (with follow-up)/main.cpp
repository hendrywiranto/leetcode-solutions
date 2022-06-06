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
        // make all listA negative
        ListNode *tempHeadA = headA;
        while(headA != nullptr){
            headA->val *= -1;
            headA = headA->next;
        }

        // while iterating listB, look for negative value
        // if found, save it to answer
        ListNode *answer = nullptr;
        while(headB != nullptr){
            if(headB->val < 0){
                answer = headB;
                break;
            }
            headB = headB->next;
        }

        // return back the listA to positive value
        while(tempHeadA != nullptr){
            tempHeadA->val *= -1;
            tempHeadA = tempHeadA->next;
        }

        return answer;
    }
};
