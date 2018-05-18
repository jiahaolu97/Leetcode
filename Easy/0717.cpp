class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for(i=0;i<bits.size()-1;i++){
            if(!bits[i]) continue;
            i++;
        }
        if(i==bits.size()-1) return true;
        return false;
    }
};
