class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size()==0) return 0;
        int co[A.size()];
        for(int i=0;i<A.size();i++) co[i] = i;
        int index = 0;
        int fn = 0;
        int cnt = 0;
        int res = INT_MIN;
        for(int i=0;i<A.size();i++){
            index = i;
            fn = 0;
            cnt = 0;
            while(cnt<A.size()){
                fn += index*A[cnt];
                index++;
                cnt++;
                if(index==A.size()) index = 0;
            }
            res = res<fn?fn:res;
        }
        return res;
    }
};
