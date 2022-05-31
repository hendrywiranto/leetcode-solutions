class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<int,bool> mp;
        int n = size(s);

        for(int i=0;i<=n-k;i++){
            string temp = s.substr(i, k);
            int conversion = stoi(temp, nullptr, 2);
            if(mp[conversion]) continue;
            mp[conversion] = true;
        }
        for(int i=0;i<(1<<k);i++){
            if(!mp[i]) return false;
        }

        return true;
    }
};
