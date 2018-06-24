class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())  return false;
        if(A.size() == 0) return false;
        int diff = 0;
        set<char> s;
        bool repeat = false;
        char c1 = 0;
        char c2 = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i]){
                diff++;
                if(diff>=3) return false;
                if(!c1){
                    c1 = A[i];  c2 = B[i];
                }else{
                    if(c1==B[i] && c2==A[i])    continue;
                    return false;
                }
            }
            else{
                if(s.count(A[i])) repeat = true;
                else s.insert(A[i]);
            }
        }
        if(diff==2) return true;
        if(diff==0 && repeat)   return true;
        return false;
    }
};
