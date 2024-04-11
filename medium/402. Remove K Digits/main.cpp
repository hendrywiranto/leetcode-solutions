class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";

        string st;
        int i = 0;
        for(;i<num.size();i++){
            while(st.size() && st.back() > num[i] && k > 0){
                st.pop_back();
                k--;
            }
            if(st.size() || num[i] != '0') st.push_back(num[i]);
        }
        while(k && st.size()){
            st.pop_back();
            k--;
        }

        return st == "" ? "0" : st;
    }
};
