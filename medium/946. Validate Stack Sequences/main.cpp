class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        unordered_map<int,int> mp;
        int last = 0;

        for(int i=0;i<pushed.size();i++){
            mp[pushed[i]] = i;
        }

        for(int i=0;i<popped.size();i++){
            if(mp[popped[i]] < last){
                if(st.top() == popped[i]){
                    st.pop();
                    mp[popped[i]] = -1;
                    continue;
                }
                else return false;
            }

            while(last < mp[popped[i]]){
                if(mp[pushed[last]] != -1) st.push(pushed[last]);

                last++;
            }

            mp[popped[i]] = -1;
        }

        return true;
    }
};
