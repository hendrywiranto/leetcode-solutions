class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string tmp;
        if(str1.size() < str2.size()) tmp = str1;
        else tmp = str2;

        int n = tmp.size();
        while(n > 0){
            if(str1.size() % n == 0 && str2.size() % n == 0){
                bool found = true;
                for(int i=0;i<str1.size();i++){
                    if(str1[i] != tmp[i%n]){
                        found = false;
                        break;
                    }
                }
                for(int i=0;i<str2.size();i++){
                    if(str2[i] != tmp[i%n]){
                        found = false;
                        break;
                    }
                }

                if(found) return tmp.substr(0, n);
            }
            n--;
        }

        return "";
    }
};
