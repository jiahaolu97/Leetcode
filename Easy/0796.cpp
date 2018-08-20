class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()) return false;
        if(A==B) return true;
        for(int i=0;i<A.size();i++){
            if(A.substr(0,i)!=B.substr(B.size()-i,i) || A.substr(i,B.size()-i)!=B.substr(0,B.size()-i))
                continue;
            else
                return true;
        }
        return false;
    }
};
