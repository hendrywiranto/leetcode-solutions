class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;

        explore(0, s, temp, result);

        return result;
    }

    void explore(int l, string s, vector<string> &temp, vector<vector<string>> &result){
        if(l >= s.size()){
            result.push_back(temp);
            return;
        }

        for(int k=1;k<=s.size()-l;k++){
            if(!isPalindrome(s, l, l+k-1)) continue;

            temp.push_back(s.substr(l, k));
            explore(l+k, s, temp, result);
            temp.pop_back();
        }
    }

    bool isPalindrome(string s, int l, int r){
        while(l<=r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }

        return true;
    }
};
