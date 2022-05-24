class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> arr = vector<bool>(s.size(), false);
        int result = 0;
        int curr = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == 40) st.push(i); // 40 is ascii for (
            else {
                if(st.empty()) continue;
                else {
                    arr[st.top()] = true;
                    arr[i] = true;
                    st.pop();
                }
            }
        }

        for(int i=0;i<s.size();i++){
            if(arr[i]) curr++;
            else {
                result = max(result, curr);
                curr = 0;
            }
        }

        return max(result, curr);
    }
};
