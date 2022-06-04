class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *last = nullptr;
        ListNode *result = nullptr;
        ListNode *resultHead = nullptr;
        ListNode *lastHead = nullptr, *lastTail = nullptr;
        int i = 0;
        bool findHead = false;

        do {
            last = head;
            head = head->next;
            last->next = result;
            result = last;
            i++;

            if(i == 1){
                lastHead = result;
            }
            if(i == k && findHead == false){
                findHead = true;
                resultHead = result;
            }
            if(i == k){
                if(lastTail != nullptr) lastTail->next = last;
                lastHead->next = head;
                result = nullptr;
                i = 0;
                lastTail = lastHead;
            }
        } while(head != nullptr);

        if(i < k && i != 0){
            result = nullptr;
            head = last;
            while(head != lastHead){
                last = head;
                head = head->next;
                last->next = result;
                result = last;
            }

            lastHead->next = result;
        }

        return resultHead;
    }
};
