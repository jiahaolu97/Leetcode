class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int next = -1;
        int last = -1;
        vector<int> res(S.size());
        while(S[next]!=C) next++;
        cout<<next<<endl;
        for(int i=0;i<S.size();i++){
            if(S[i]  == C){
                res[i] = 0;
                last = i;
                next ++;
                while(next<S.size() && S[next]!=C)  next++;
                cout << next << endl;
            }else{
                int l = i - last;
                int r = next - i;
                if(last!= -1 && next!=S.size())
                    res[i] = l>r?r:l;
                else
                    if(last== -1) res[i] = r;
                    if(next== S.size()) res[i]=l;
            }
        }
        return res;
    }
};
