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
    int leftMost = 0;
    int totalLevel = -1;
    int finalTotal = 0;
public:
    int countNodes(TreeNode* root) {
        dfs(root);
        return finalTotal + leftMost;
    }

    void dfs(TreeNode* root, int level = 0, int total = 0){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr && totalLevel == -1){
            totalLevel = level;
            finalTotal = total;
        }
        if(root->left == nullptr && root->right == nullptr && level == totalLevel){
            leftMost++;
            return;
        }

        dfs(root->left, level+1, total+pow(2, level));
        dfs(root->right, level+1, total+pow(2, level));

        return;
    }
};
