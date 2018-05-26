class Solution {
public:
    bool isChar(char c){
        if(c>='a'&&c<='z') return true;
        if(c>='A'&&c<='Z') return true;
        return false;
    }
    
    string mostCommonWord(string p, vector<string>& banned) {
        map<string,int> m;
        int idx = -1;   //last position where a non-character stands
        for(int i=0;i<p.length();i++){
            if(!isChar(p[i])){
                if(idx!=i-1){
                    string key = p.substr(idx+1,i-idx-1);
                    int cnt = m.count(key);
                    if(cnt==0) m.insert(pair<string,int>(key,1));
                    else{
                        int val = m.find(key)->second;
                        m.find(key)->second = val+1;
                    }
                }
                idx = i;
            }else{
                if(p[i]>='A' && p[i]<='Z')
                    p[i] = p[i]-'A'+'a';
            }
        }
        if(idx!=p.length()-1){
            string key = p.substr(idx+1,p.length()-idx-1);
            int cnt = m.count(key);
            if(cnt==0) m.insert(pair<string,int>(key,1));
            else{
                int val = m.find(key)->second;
                m.find(key)->second = val+1;
            }
        }
        map<string,int>::iterator it;
        int max = 0;
        string cur;
        for(it = m.begin();it!=m.end();it++){
            if(it->second<=max) continue;
            bool ban = false;
            for(int j=0;j<banned.size();j++){
                if(banned[j]==it->first){
                    ban = true;
                    break;
                }
            }
            if(!ban){
                max = it->second;
                cur = it->first;
            } 
        }
        return cur;
    }
};
