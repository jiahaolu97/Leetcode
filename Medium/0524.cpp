class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result;
        if(d.size()==0 || s.size()==0) return result;
        for(int i=0;i<d.size();i++){
            if(match(s,d[i])){
                if(d[i].size()>result.size()){
                    result = d[i];
                }else if(d[i].size()==result.size()){
                    if(d[i]<result)   result = d[i];
                }
            }
        }
        return result;
    }
    bool match(string s, string t){
        int a = 0;
        int b = 0;
        while(a<s.size() && b<t.size()){
            if(s[a] == t[b]){
                a++;
                b++;
            }else{
                a++;
            }
        }
        if(b==t.size()) return true;
        return false;
    }
};
