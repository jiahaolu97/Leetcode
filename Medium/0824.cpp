class Solution {
public:
    bool isChar(char c){
        if(c>='a'&&c<='z') return true;
        if(c>='A'&&c<='Z') return true;
        return false;
    }
    bool isVowel(char c){
        if(c<='Z'&&c>='A') c = c-'A'+'a';
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }

    string change(string S,int num){
        string res;
        if(isVowel(S[0])){
            res += S;
            res.append("ma");
        }else{
            res = S.substr(1,S.length()-1);
            res.push_back(S[0]);
            res.append("ma");
        }
        for(int i=0;i<num;i++){
            res.append("a");
        }
        return res;
    }
    string toGoatLatin(string S) {
        int idx = 0;
        int num = 0;
        string res;
        while(idx!=S.length()){
            if(isChar(S[idx])){
                num++;
                string tmp;
                while(isChar(S[idx])){
                    tmp.push_back(S[idx]);
                    idx++;
                }
                idx--;
                string add = change(tmp,num);
                res.append(add);
            }else{
                res.push_back(S[idx]);		
            }
            idx++;
        }
    //    cout << res;
        return res;
    }
};
