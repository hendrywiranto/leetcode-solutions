class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int special = arr[0];
        int len = 1;        

        for(int i=1;i<arr.size();i++){
            if(arr[i] != special){
                if(float(len)/arr.size() > 0.25){
                    return special;
                }
                special = arr[i];
                len = 1;
            }
            else len++;            
        }

        return special;;
    }
};
