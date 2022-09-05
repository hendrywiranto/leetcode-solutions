/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;

        if(root == nullptr) return result;

        q.push(root);
        result.push_back({root->val});
        q.push(nullptr);

        vector<int> temp;

        while(!q.empty()){
            Node* now = q.front();
            if(now == nullptr){
                if(temp.size() != 0){
                    result.push_back(temp);
                    temp = {};
                    q.push(nullptr);
                }
            }
            else {
                 for(int i=0;i<now->children.size();i++){
                    temp.push_back(now->children[i]->val);
                    q.push(now->children[i]);
                }
            }
            q.pop();
        }

        return result;
    }
};
