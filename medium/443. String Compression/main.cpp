class Solution {
public:
    int compress(vector<char>& chars) {
        int f = 0;
        int ctr = 0;
        char now = chars[0];

        for(int i=0;i<chars.size();i++){
            if(now != chars[i]){
                chars[f++] = now;
                if(ctr != 1){
                    string sctr = to_string(ctr);
                    for(int j=0;j<sctr.size();j++){
                        chars[f++] = sctr[j];
                    }
                }

                now = chars[i];
                ctr = 1;
            }
            else ctr++;
        }

        // last ctr insertion
        if(f != chars.size()-1){
            chars[f++] = now;
            if(ctr != 1){
                string sctr = to_string(ctr);
                for(int j=0;j<sctr.size();j++){
                    chars[f++] = sctr[j];
                }
            }
        }
        else f++; // including last char in array

        return f;
    }
};
