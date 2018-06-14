class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> a,b;
        for(int i=0;i<S.size();i++){
            char c = S[i];
            if(c!='#'){
                a.push(c);
            }else{
                if(a.size()>0)
                    a.pop();
            }
        }
        for(int i=0;i<T.size();i++){
            char c = T[i];
            if(c!='#')  b.push(c);
            else
                if(b.size()>0)  b.pop();
        }
        if(a.size() != b.size()) return false;
        if(a.size() == 0) return true;
        while(a.size()>0){
            if(a.top()!=b.top()) return false;
            a.pop();
            b.pop();
        }
        return true;
    }
};
