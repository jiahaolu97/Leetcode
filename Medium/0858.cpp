class Solution {
public:    
    int mirrorReflection(int p, int q) {
        int n = 1;
        while(true){
            if(n*p % q == 0){
                int m = n*p/q;
                if(n%2){
                    if(m%2) return 1;
                    return 2;
                }else{
                    if(m%2){
                        return 0;
                    }else{
                        n++;
                        continue;
                    }
                }
            }
            else n++;
        }
    }
};
