class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<string> strings = { "" };
        strings.insert(strings.end(), strs.begin(), strs.end());
        int arr[strings.size()][m+1][n+1];

        for(int i=0;i<strings.size();i++){
            string now = strings[i];
            int zeros = count(now.begin(), now.end(), '0');
            int ones = count(now.begin(), now.end(), '1');

            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(i == 0 || (j == 0 && k == 0)) arr[i][j][k] = 0;
                    else if(zeros <= j && ones <= k){
                        arr[i][j][k] = max(1 + arr[i-1][j-zeros][k-ones], arr[i-1][j][k]);
                    }
                    else arr[i][j][k] = arr[i-1][j][k];
                }
            }
        }

        return arr[strings.size()-1][m][n];
    }
};
