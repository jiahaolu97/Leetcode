class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len<=2) return 0;
        int res = 0;
        for(int i=2;i<len;i++){
            int gap = A[i] - A[i-1];
            for(int j=i-1;j>0;j--){
                if(gap == A[j]-A[j-1]) res++;
                else break;
            }
        }
        return res;
    }
};
