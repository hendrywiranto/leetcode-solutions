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
    int pairSum(ListNode* head) {
        vector<int> v;

        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        int result = 0, n = v.size();
        for(int i=0;i<n;i++){
            result = max(result, v[i] + v[n - i -1]);
        }

        return result;
    }
};
