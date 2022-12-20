class Solution {
private:
    int counter = 0;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> memo(1000, 0);

        traverse(rooms, memo, 0);
        return counter == rooms.size();
    }

    void traverse(vector<vector<int>>& rooms, vector<int>& memo, int now){
        if(memo[now] == 1){
            return;
        }

        counter++;
        memo[now]=1;
        for(int i=0;i<rooms[now].size();i++){
            traverse(rooms, memo, rooms[now][i]);
        }

        return;
    }
};
