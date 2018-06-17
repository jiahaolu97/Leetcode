class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = A[0];
        for(int i=1;i<A.size();i++){
            if(A[i]<l) return i-1;
            l = A[i];
        }
    }
};
