class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for(int i=1;i<=sqrt(2*N);i++){
            if((2*N)%i==0){
                int base = 2*N/i;
                if(base%2==1 && i%2==0 && base>i) res++;
                if(base%2==0 && i%2==1 && base>i) res++;
            }
            
        }
        return res;
    }
};
