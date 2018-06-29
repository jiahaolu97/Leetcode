class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size()<=2) return 0;
        int max = 0;
        bool up = false;
        bool down = false;
        int cur = 0;
        for(int i=1;i<A.size();i++){
            int last = A[i-1];
            if(!up && !down){   //restart
                cur = 1;
                if(A[i-1]<A[i]){
                    up = true;
                    cur++;
                }else   continue;
            }else if(up && !down){
                if(A[i-1]<A[i]){
                    cur++; continue;
                }else if(A[i-1]==A[i]){
                    up = false;
                    down = false;
                }else{
                    cur++;
                    down = true;
                }
            }else if(up && down){
                if(A[i-1]>A[i]){
                    cur++;
                }else{
                    max = cur>max?cur:max;
                    if(A[i-1] == A[i]){
                        up =    false;
                        down = false;
                    }else{
                        cur = 2;
                        up = true;
                        down = false;
                    }
                }
            }
        }
        if(up && down && cur>max)   max = cur;
        return max;
    }
};
