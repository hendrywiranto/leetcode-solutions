/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findNode(root, p);
        findNode(root, q);

        return result;
    }

    bool findNode(TreeNode* root, TreeNode* target){
        if(root == nullptr) return false;
        if(root == target || findNode(root->left, target) || findNode(root->right, target)){
            if(memo.find(root->val) != memo.end() && result == nullptr) result = root;
            memo[root->val] = true;
            return true;
        }

        return false;
    }

private:
    map<int,bool> memo;
    TreeNode* result = nullptr;
};
