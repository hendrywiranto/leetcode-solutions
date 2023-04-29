class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";

        int i = a.size()-1, j = b.size()-1;
        int carry = 0;

        while(i >= 0 || j >= 0){
            int total = carry;
            if(i >= 0) total += a[i--] - '0';
            if(j >= 0) total += b[j--] - '0';

            str += ('0' + total % 2);
            carry = total / 2;
        }
        if(carry > 0) str += '1';
        reverse(str.begin(), str.end());

        return str;
    }
};
