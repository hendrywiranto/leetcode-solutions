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
    int i = 0;
    bool leafSimilarCheck = true;
    queue<int> qu;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        firstTraverse(root1);
        secondTraverse(root2);

        return qu.empty() && leafSimilarCheck;
    }

    void firstTraverse(TreeNode* root){
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            qu.push(root->val);
            return;
        }
        firstTraverse(root->left);
        firstTraverse(root->right);
    }

    void secondTraverse(TreeNode* root){
        if(!leafSimilarCheck) return;
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            if(qu.front() != root->val || qu.empty()){
                leafSimilarCheck = false;

                return;
            }
            qu.pop();
            i++;
        }

        secondTraverse(root->left);
        secondTraverse(root->right);
    }
};
