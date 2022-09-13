class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int byteCount = 0;

        for(int i=0;i<data.size();i++){
            string temp = bitset<8>(data[i]).to_string();

            if(byteCount > 0){
                if(temp[0] != '1' || temp[1] != '0') return false;

                byteCount--;
            }
            else {
                for(byteCount = 0;byteCount<temp.size();byteCount++){
                    if(temp[byteCount] != '1') break;
                }

                if(byteCount > 4) return false;
                if(byteCount == 1) return false;
                if(byteCount > 1) byteCount--;
            }

        }

        return byteCount == 0;
    }
};
