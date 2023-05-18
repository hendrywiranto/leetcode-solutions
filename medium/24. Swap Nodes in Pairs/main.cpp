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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first = head, *second, *prev = nullptr, *next;
        head = nullptr;

        while(first != nullptr){
            second = first->next;
            if(second == nullptr) break;

            first->next = second->next;
            if(prev != nullptr) prev->next = second;
            second->next = first;
            if(head == nullptr) head = second;

            prev = first;
            first = prev->next;
        }

        return head == nullptr ? first : head;
    }
};
