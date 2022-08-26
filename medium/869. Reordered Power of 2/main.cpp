class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string numb = to_string(n);
        sort(numb.begin(), numb.end());

        for(int i=0;i<30;i++){
            string temp = to_string(int(pow(2, i)));
            sort(temp.begin(), temp.end());

            if(temp == numb) return true;
        }

        return false;
    }
};
