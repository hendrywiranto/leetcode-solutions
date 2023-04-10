class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - b.size();

        if(n > 0){
            string tmp = "";
            while(n > 0){
                tmp += "0";
                n--;
            }
            b = tmp + b;
        }
        else {
            string tmp = "";
            n = abs(n);
            while(n > 0){
                tmp += "0";
                n--;
            }
            a = tmp + a;
        }

        string result = "";
        int remainder = 0;
        for(int i=a.size()-1;i>=0;i--){
            int now = 0;
            if(a[i] == '1') now++;
            if(b[i] == '1') now++;
            if(remainder == 1) now++;
            if(now == 3){
                result = '1' + result;
                remainder = 1;
            }
            else if(now == 2){
                result = '0' + result;
                remainder = 1;
            }
            else if(now == 1){
                result = '1' + result;
                remainder = 0;
            }
            else {
                result = '0' + result;
                remainder = 0;
            }
        }

        if(remainder == 1) result = '1' + result;
        else if(result == "") result = "0";
        return result;
    }
};
