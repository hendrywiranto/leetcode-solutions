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
    TreeNode* pruneTree(TreeNode* root) {
        if(haveOnes(root)) return root;
        else return nullptr;
    }

    bool haveOnes(TreeNode* root){
        if(root == nullptr) return false;

        if(!haveOnes(root->left)) root->left = nullptr;
        if(!haveOnes(root->right)) root->right = nullptr;

        if(root->val == 1) return true;
        else if(root->left != nullptr || root->right != nullptr) return true;
        else return false;
    }
};
