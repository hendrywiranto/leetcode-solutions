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
    bool isSymmetric(TreeNode* root) {
        bool result = true;

        traverse(root->left, root->right, result);

        return result;
    }

    void traverse(TreeNode *root1, TreeNode *root2, bool &result){
        if(result == false) return;
        if(root1 == nullptr && root2 == nullptr) return;
        if(root1 == nullptr || root2 == nullptr || root1->val != root2->val){
            result = false;
            return;
        }

        traverse(root1->right, root2->left, result);
        traverse(root1->left, root2->right, result);

        return;
    }
};
