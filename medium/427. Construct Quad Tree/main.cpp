/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return traverse(grid, 0, grid[0].size()-1, 0, grid.size()-1);
    }

    Node* traverse(vector<vector<int>>& grid, int x1, int x2, int y1, int y2){
        if(x1 == x2 && y1 == y2){
            bool val = grid[y1][x1] == 1 ? true : false;
            return new Node(val, true);
        }

        Node *parent = new Node();
        parent->topLeft = traverse(grid, x1, x1 + (x2-x1)/2, y1, y1 + (y2-y1)/2);
        parent->topRight = traverse(grid, x1 + (x2-x1)/2 + 1, x2, y1, y1 + (y2-y1)/2);
        parent->bottomLeft = traverse(grid, x1, x1 + (x2-x1)/2, y1 + (y2-y1)/2 + 1, y2);
        parent->bottomRight = traverse(grid, x1 + (x2-x1)/2 + 1, x2, y1 + (y2-y1)/2 + 1, y2);

        if(
            parent->topLeft->isLeaf
            && parent->topRight->isLeaf
            && parent->bottomLeft->isLeaf
            && parent->bottomRight->isLeaf
            && parent->topLeft->val == parent->topRight->val
            && parent->topRight->val == parent->bottomLeft->val
            && parent->bottomLeft->val == parent->bottomRight->val
        ) return new Node(grid[y1][x1], true);

        return parent;
    }
};
