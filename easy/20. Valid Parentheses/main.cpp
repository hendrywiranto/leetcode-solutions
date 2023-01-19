class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else {
                if(i == ')' && (st.empty() || st.top() != '(')) return false;
                if(i == '}' && (st.empty() || st.top() != '{')) return false;
                if(i == ']' && (st.empty() || st.top() != '[')) return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
