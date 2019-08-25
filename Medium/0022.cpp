class Solution {
public:
    string gen(vector<int> v){
        string res = "";
        int pre = 0;
        for(int i=0;i<v.size();i++){
            int r = v[i];
            for(int j=0;j<r-pre;j++){
                res.push_back('(');
            }
            res.push_back(')');
            pre = r;
        }
        return res;
    }
    
    void printvec(vector<int> t){
        for(int i=0;i<t.size();i++){
            cout << t[i] << ",";
        }
        cout << endl;
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0) return {""};
        if(n==1) return {"()"};
        vector<string> res;
        queue<vector<int>> q;
        for(int i=1;i<=n;i++){
            q.push({i});
        }
        vector<int> t;
        string s;
        int start;
        while(q.size()){
            t = q.front();
            if(t.size() == n){
                printvec(t);
                s = gen(t);
                res.push_back(s);
                q.pop();
                continue;
            }
            start = max((int)(t.size()+1), t[t.size()-1]);
            //start = t.size()+1 > t[t.size()-1] ? t.size()+1 : t[t.size()-1];
            for(int i=start;i<=n;i++){
                vector<int> nv(t);
                nv.push_back(i);
                q.push(nv);
            }
            q.pop();
        }
        return res;
    }
};
