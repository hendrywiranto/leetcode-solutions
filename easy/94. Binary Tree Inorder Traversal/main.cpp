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
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return result;
    }

    void traverse(TreeNode* root){
        if(root == nullptr) return;

        traverse(root->left);
        result.push_back(root->val);
        traverse(root->right);

        return;
    }
};
