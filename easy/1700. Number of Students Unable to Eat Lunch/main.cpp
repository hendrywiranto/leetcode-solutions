class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0, square = 0;

        for(auto s:students){
            if(s == 0) circle++;
            else square++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i] == 0) circle--;
            else square--;

            if(circle < 0 || square < 0) return sandwiches.size()-i;            
        }

        return 0;
    }
};
