class Solution {
public:
    bool isPalindrome(string s) {
        int front=0, back=s.size()-1;

        while(front<=back){
            while(front < back && !isalnum(s[front])){
                front++;
            }
            while(front < back && !isalnum(s[back])){
                back--;
            }

            if(tolower(s[front]) != tolower(s[back])) return false;
            front++;
            back--;
        }

        return true;
    }
};
