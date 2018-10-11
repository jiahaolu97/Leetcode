class Solution {
public:
    string toLowerCase(string str) {
        string res;
        char cur;
        for(int i=0;i<str.size();i++){
            if(str[i]>='a' && str[i]<='z') res.push_back(str[i]);
            else if(str[i]>='A' && str[i]<='Z'){
                cur = str[i] - 'A' + 'a';
                res.push_back(cur);
            }else{
                res.push_back(str[i]);
            }
        }
        return res;
    }
};
