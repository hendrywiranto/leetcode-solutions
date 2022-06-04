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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> lastIndex;

        for(int i=0;i<lists.size();i++){
            ListNode *head = lists[i];

            while(head != nullptr){
                ListNode *linkNow = head;
                head = head->next;

                if(lastIndex.find(linkNow->val) != lastIndex.end()){
                    ListNode *now = lastIndex[linkNow->val].back();
                    ListNode *temp = now->next;
                    now->next = linkNow;
                    if(linkNow != temp) linkNow->next = temp;
                    lastIndex[linkNow->val].push_back(linkNow);
                }
                else {
                    lastIndex[linkNow->val].push_back(linkNow);
                }
            }
        }

        vector<int> ki;
        map<int, vector<ListNode*>>::iterator it;
        for (it = lastIndex.begin(); it != lastIndex.end(); it++){
            ki.push_back(it->first);
        }

        if(lists.size() == 0 || ki.size() == 0) return nullptr;

        vector<ListNode*> next;
        int i = 0;

        for (it = lastIndex.begin(); it != lastIndex.end() && i < ki.size()-1; it++){
            next = lastIndex[ki[i + 1]];
            it->second.back()->next = next.front();
            i++;
        }

        return lastIndex[ki[0]].front();
    }
};
