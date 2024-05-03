class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;

        int last = 0, i = 0;
        for(;i<version1.size();i++){
            if(version1[i] == '.'){
                v1.push_back(version1.substr(last, i-last));
                last = i+1;
            }
        }
        v1.push_back(version1.substr(last, i-last));

        last = 0, i = 0;
        for(;i<version2.size();i++){
            if(version2[i] == '.'){
                v2.push_back(version2.substr(last, i-last));
                last = i+1;
            }
        }
        v2.push_back(version2.substr(last, i-last));
    
        for(i=0;i<v1.size() && i<v2.size();i++){
            if(stoi(v1[i]) < stoi(v2[i])){
                return -1;
            }
            else if(stoi(v1[i]) > stoi(v2[i])){
                return 1;
            }
        }
        int n1 = i, n2 = i;
        while(n1 < v1.size()){            
            if(stoi(v1[n1]) > 0) return 1;
            n1++;
        }
        while(n2 < v2.size()){           
            if(stoi(v2[n2]) > 0) return -1;
            n2++;
        }

        return 0;
    }
};
