class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;

        map<pair<int,int>,bool> m;
        m[make_pair(x,y)] = true;

        for(auto p:path){
            if(p == 'N') y--;
            if(p == 'E') x++;
            if(p == 'S') y++;
            if(p == 'W') x--;

            pair<int,int> pr = make_pair(x,y);
            if(m.find(pr) != m.end()) return true;

            m[pr] = true;
        }

        return false;
    }
};
