class Solution {
public:
    char reg(char c){
	    if(c>='a' && c<='z') return c;
	    return c-'A'+'a';
    }
    string maskPII(string S) {
        string res;
        if(S.find_first_of('@')!=-1){
            int a = S.find_first_of('@');
            int b = S.find_first_of('.');
            res.push_back(reg(S[0]));
            for(int j=0;j<5;j++){
                res.push_back('*');
            }
            res.push_back(reg(S[a-1]));
            res.push_back('@');
            for(int j=a+1;j<b;j++)	res.push_back(reg(S[j]));
            res.push_back('.');
            for(int j=b+1;j<S.length();j++) res.push_back(reg(S[j]));
        }else{
            string temp;
            for(int i=S.length()-1;i>=0;i--){
                if(S[i]>='0' && S[i]<='9') temp.push_back(S[i]);
            }
            if(temp.length()>10){
                res.push_back('+');
                for(int i=temp.length()-1;i>=10;i--){
                    res.push_back('*');
                }
                res.push_back('-');
            }
            res.append("***-***-");
            for(int i=3;i>=0;i--){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};
