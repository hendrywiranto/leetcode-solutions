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
    string result = "";

public:
    string tree2str(TreeNode* root) {
        traverse(root);

        result.pop_back();

        return result;
    }

    void traverse(TreeNode* root, string leaf = "left"){
        if(root == nullptr){
            return;
        }

        if(leaf == "right" && result.back() != ')'){
            result += "()";
        }
        if(result.size() != 0) result += "(";

        result += to_string(root->val);
        traverse(root->left);
        traverse(root->right, "right");
        result += ")";

        return;
    }
};
