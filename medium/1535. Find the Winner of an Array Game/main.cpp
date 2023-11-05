class Solution {

struct ListNode {
    int val;
    int wins = 0;
    ListNode *next, *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

private:
    ListNode *head, *tail;

    void insertBack(ListNode *temp){
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev->next = temp;
        tail->prev = temp;
    }

    void unlinkNode(ListNode *temp){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->next = nullptr;
        temp->prev = nullptr;        
    }

    void moveToBack(ListNode *temp){
        unlinkNode(temp);
        insertBack(temp);
    }

public:
    int getWinner(vector<int>& arr, int k) {                         
        head = new ListNode();
        tail = new ListNode();

        head->next = tail;
        tail->prev = head;

        for(auto a:arr){
            ListNode *temp = new ListNode(a);
            insertBack(temp);
        }
        
        while(head->next->wins < k){
            if(head->next->wins >= arr.size()-1){
                return head->next->val;
            }

            if(head->next->val < head->next->next->val){
                head->next->next->wins++;
                moveToBack(head->next);
            }
            else {
                head->next->wins++;
                moveToBack(head->next->next);
            }
        }

        return head->next->val;
    }
};
