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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead = nullptr, *oddHead = nullptr;
        ListNode *even = nullptr, *odd = nullptr;
        int i = 1;

        while(head != nullptr){
            if(i % 2 == 1){
                if(odd == nullptr){
                    odd = head;
                    oddHead = head;
                }
                else {
                    odd->next = head;
                    odd = head;
                }
            }
            else {
                if(even == nullptr){
                    even = head;
                    evenHead = head;
                }
                else {
                    even->next = head;
                    even = head;
                }
            }

            head = head->next;
            i++;
        }

        if(even != nullptr) even->next = nullptr;
        if(odd != nullptr) odd->next = evenHead;

        return oddHead;
    }
};
