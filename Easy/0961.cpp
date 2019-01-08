class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        //int size = A.size();
        set<int> s;
        for(int i=0;i<A.size();i++){
            if(s.count(A[i])==0){
                s.insert(A[i]);
            }else
                return A[i];
        }
    }
};
