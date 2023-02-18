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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = INT_MAX;
        traverse(root, minDiff, prev);
        return minDiff;
    };

    void traverse(TreeNode *root, int &minDiff, int &prev){
        if(root == nullptr) return;

        traverse(root->left, minDiff, prev);

        minDiff = min(minDiff, abs(root->val - prev));
        prev = root->val;

        traverse(root->right, minDiff, prev);

        return;
    }
};
