class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), cmp);

        return LongestIncreasingSubsequenceLength(env);
    }

private:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int CeilIndex(vector<vector<int>>& v, int l, int r, vector<int>& key)
    {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (v[m][1] >= key[1]) r = m;
            else l = m;
        }

        return r;
    }

    int LongestIncreasingSubsequenceLength(vector<vector<int>>& v)
    {
        if (v.size() == 0) return 0;

        vector<vector<int>> tail(v.size(), {0, 0});
        int length = 1;

        tail[0] = v[0];
        for (size_t i = 1; i < v.size(); i++) {

            if (v[i][1] < tail[0][1])
                tail[0] = v[i];
            else if (v[i][1] > tail[length-1][1])
                tail[length++] = v[i];
            else
                tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }

        return length;
    }
};
