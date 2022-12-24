class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == destination) return true;
            for(auto e : adj[now]){
                if(!visited[e]){
                    visited[e] = true;
                    q.push(e);
                }
            }
        }

        return false;
    }
};
