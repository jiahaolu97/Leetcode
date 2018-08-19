class Solution {
public:
    bool isgood(int n){
        int l;
        bool same = true;
        while(n>0){
            l = n%10;
            if(l==3 || l==4 || l==7) return false;
            if(l==2 || l==5 || l==6 || l==9) same = false;
            n /= 10;
        }
        if(same) return false;
        return true;
    }
    
    int rotatedDigits(int N) {
        int res = 0;
        for(int i=1;i<=N;i++){
            if(isgood(i)) res++;
        }
        return res;
    }
};
