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
public:
    int maxDepth(TreeNode* root) {
        int deepest = 0;

        traverse(root, deepest);

        return deepest;
    }

    void traverse(TreeNode *root, int &deepest, int now = 1){
        if(root == nullptr) return;
        if(now > deepest) deepest = now;

        traverse(root->left, deepest, now+1);
        traverse(root->right, deepest, now+1);
    }
};
