class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,bool> outpaths;

        for(int i=0;i<paths.size();i++){
            outpaths[paths[i][0]] = true;
            if(outpaths.find(paths[i][1]) == outpaths.end()) outpaths[paths[i][1]] = false;
        }

        for(auto op:outpaths){
            if(!op.second){
                return op.first;
            }
        }

        return "";
    }
};
