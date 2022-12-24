class Solution {
private:
    vector<int> rank;
    vector<int> parent;

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        rank = vector<int>(n, 0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;

        for(auto e : edges){
            unite(e[0], e[1]);
        }

        return find(source) == find(destination);
    }

    int find(int x){
        if(parent[x] == x) return x;
        else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;
        else {
            if(rank[px] > rank[py]){
                parent[py] = px;
            }
            else if(rank[px] < rank[py]){
                parent[px] = py;
            }
            else {
                parent[px] = py;
                rank[py]++;
            }
        }
    }
};
