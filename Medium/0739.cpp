class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int> > s;
        vector<int> res(t.size(),0);
        for(int i=0;i<t.size();i++){
            int cur = t[i];
            // int num = 0;
            while(s.size()>0 && s.top().first < cur){
                int pos = s.top().second;
                s.pop();
                res[pos] = (i-pos);
            }
            s.push(pair<int,int>(cur,i) );
        }
        return res;
    }
};
