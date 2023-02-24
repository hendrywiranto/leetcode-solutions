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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans, bfs = {};

        queue<TreeNode*> q;

        q.push(nullptr);
        q.push(root);

        while(!q.empty()){
            if(q.front() == nullptr){
                if(q.back() == nullptr) break;

                q.push(nullptr);
                bfs.push_back({});
            }
            else {
                TreeNode *curr = q.front();
                bfs.back().push_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }

            q.pop();
        }

        for(int i=0;i<bfs.size();i++){
            ans.push_back({});
            if(i % 2 == 0){
                for(int j=0;j<bfs[i].size();j++){
                    ans.back().push_back(bfs[i][j]);
                }
            }
            else {
                for(int j=bfs[i].size()-1;j>=0;j--){
                    ans.back().push_back(bfs[i][j]);
                }
            }
        }

        return ans;
    }
};
