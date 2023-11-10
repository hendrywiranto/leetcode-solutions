class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> m1;

        for(int i=0;i<adjacentPairs.size();i++){
            m1[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m1[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int first = 0;
        for(auto m:m1){
            if(m.second.size() == 1) first = m.first;
        }

        vector<int> result = { first };
        map<int,bool> visited;
        traverse(result, first, visited, adjacentPairs.size()+1, m1);
        return result;     
    }

    void traverse(vector<int> &result, int node, map<int,bool> &visited, int target, map<int,vector<int>> &m1){
        if(result.size() == target) return;
        visited[node] = true;

        for(auto n:m1[node]){
            if(visited[n]) continue;

            result.push_back(n);
            traverse(result, n, visited, target, m1);
        }

        return;
    }
};
