class Solution {
private:
    long long int combCount(long long int n){
        long long int result = n * (n+1) / 2;
        return result;
    }
    
public:
    int countHomogenous(string s) {
        vector<int> lengthCount(s.size()+1);

        char lastLetter = s[0];
        int i = 1;
        int n = 1;
        while(i<s.size()){
            if(lastLetter != s[i]){
                lengthCount[n]++;
                lastLetter = s[i];
                n = 0;                
            }
            n++;
            i++;
        }
        lengthCount[n]++;

        long long int result = 0;
        for(i=1;i<lengthCount.size();i++){
            result += (combCount(i) * lengthCount[i]) % 1000000007;
        }

        return int(result);
    }
};
