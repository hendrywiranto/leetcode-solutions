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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = nullptr;
        root->right = nullptr;

        if(current != nullptr) current->right = root;
        current = root;

        flatten(left);
        flatten(right);

        return;
    }

private:
    TreeNode *current = nullptr;
};
