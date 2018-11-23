class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        bool up = true;
        if(A[1] <= A[0]) return false;
        for(int i=1;i<A.size();i++){
            if(up){
                if(A[i]>A[i-1]) continue;
                else if(A[i] == A[i-1]) return false;
                else up = false;
            }else{
                if(A[i] == A[i-1]) return false;
                if(A[i] > A[i-1]) return false;
            }
        }
        if(up == true) return false;
        return true;
    }
};
