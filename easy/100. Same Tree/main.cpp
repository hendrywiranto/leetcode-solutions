/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool result = true;
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p, q);
        return result;
    }

    void traverse(TreeNode *p, TreeNode *q){
        if(!result) return;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)){
            result = false;
            return;
        }
        if(p == nullptr && q == nullptr) return;
        if(p->val != q->val){
            result = false;
            return;
        }
        traverse(p->left, q->left);
        traverse(p->right, q->right);

        return;
    }
};
