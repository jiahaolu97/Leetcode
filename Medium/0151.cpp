class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        string cur;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                cur.push_back(s[i]);
            }else{
                if(cur!="")
                    words.push_back(cur);
                cur.clear();
            }
        }
        if(s[s.size()-1]!=' ')
            words.push_back(cur);
        string res;
        for(int j=words.size()-1;j>=0;j--){
            res.append(words[j]);
            if(j!=0) res.push_back(' ');
        }
        s.clear();
        s = res;
    }
};
