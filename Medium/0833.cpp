class Solution {
public:
    string findReplaceString(string S, vector<int>& in, vector<string>& so, vector<string>& ta) {
        map<int,int> m;
        for(int i=0;i<in.size();i++){
            m.insert(pair<int,int>(in[i],i));
        }
        map<int,int>::iterator it;
        vector<int> indexes;
        vector<string> sources;
        vector<string> targets;
        for(it=m.begin();it!=m.end();it++){
            int val = it->second;
            indexes.push_back(in[val]);
            sources.push_back(so[val]);
            targets.push_back(ta[val]);
        }

        int last = 0;
        string res;
        for(int i=0;i<indexes.size();i++){
            int pos = indexes[i];
            res.append(S.substr(last,pos-last));
            last = pos;
            int len = sources[i].length();
            if(S.substr(pos,len)==sources[i]){
                last = pos+len;
                res.append(targets[i]);
            }
        }
        for(int i=last;i<S.length();i++){
            res.push_back(S[i]);
        }
        return res;
    }
};
