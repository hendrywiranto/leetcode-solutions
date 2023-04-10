class Solution {
public:
    bool isValid(string ss) {
        stack<char> st;

        for(auto s:ss){
            if(s == '(' || s == '[' || s == '{'){
                st.push(s);
            }
            else {
                if(st.empty()) return false;

                if(s == ')' && st.top() != '(') return false;
                if(s == ']' && st.top() != '[') return false;
                if(s == '}' && st.top() != '{') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
