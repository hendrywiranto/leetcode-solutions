class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;

        int front = 0;

        for(int i=0;i<=haystack.size() - needle.size();i++){
            if(compare(haystack, i, needle)) return i;
        }

        return -1;
    }

    bool compare(string origin, int front, string target){
        for(int i=0;i<target.size();i++){
            if(origin[front + i] != target[i]) return false;
        }

        return true;
    }
};
