class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > res;
        map<int,int> m;
        char last = S[0];
        int lastidx = 0;
        int len = 1;
        for(int i=1;i<S.length();i++){
            if(S[i]!=last){
                if(len>=3){
                    m.insert(pair<int,int>(lastidx,i-1));
                }
                last = S[i];
                lastidx = i;
                len = 1;
            }else{
                len++;
            }
        }
        if(len>=3){
		    m.insert(pair<int,int>(lastidx,S.length()-1));
	    }
        map<int,int>::iterator it;
        for(it = m.begin();it!=m.end();it++){
            vector<int> line;
            line.push_back(it->first);
            line.push_back(it->second);
            res.push_back(line);
        }
        return res; 
    }
};
