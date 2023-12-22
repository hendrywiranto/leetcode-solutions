class Solution {
private:
    int smoothen(vector<vector<int>>& img, int y, int x) {
        int cellCtr = 1;
        int total = img[y][x];

        if(x-1 >= 0){
            cellCtr++;
            total += img[y][x-1];
        }
        if(x-1 >= 0 && y+1 < img.size()){
            cellCtr++;
            total += img[y+1][x-1];
        }
        if(y+1 < img.size()){
            cellCtr++;
            total += img[y+1][x];
        }
        if(y+1 < img.size() && x+1 < img[y+1].size()){
            cellCtr++;
            total += img[y+1][x+1];
        }
        if(x+1 < img[y].size()){
            cellCtr++;
            total += img[y][x+1];
        }
        if(y-1 >= 0 && x+1 < img[y-1].size()){
            cellCtr++;
            total += img[y-1][x+1];
        }
        if(y-1 >= 0){
            cellCtr++;
            total += img[y-1][x];
        }
        if(x-1 >= 0 && y-1 >= 0){
            cellCtr++;
            total += img[y-1][x-1];
        }
        cout << total << endl;
        cout << cellCtr << endl;
        cout << float(total) / float(cellCtr) << endl << endl;

        return floor(float(total) / float(cellCtr));
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result(img.size(), vector<int>(img[0].size()));

        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[i].size();j++){
                result[i][j] = smoothen(img, i, j);
            }
        }

        return result;
    }
};
