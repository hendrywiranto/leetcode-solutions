class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diffs(s.size(), 0);
        for(int i=0;i<s.size();i++){
            diffs[i] = abs(s[i] - t[i]);
        }

        int l = 0, r = 0;
        int curr = 0;
        int ans = 0;
        while(r < diffs.size()){
            curr += diffs[r];
            while(curr > maxCost && l <= r && l+1 < diffs.size()){                
                curr -= diffs[l];
                l++;
            }

            if(curr <= maxCost) ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
