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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, 0, sum);

        return sum;
    }

    void traverse(TreeNode *root, int now, int &sum){
        if(root == nullptr) return;
        now += root->val;

        if(root->left == nullptr && root->right == nullptr){
            sum += now;
            return;
        }

        traverse(root->left, now * 10, sum);
        traverse(root->right, now * 10, sum);

        return;
    }
};
