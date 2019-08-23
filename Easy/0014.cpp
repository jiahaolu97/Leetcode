class Solution {
public:
    string Prefix(string a, string b){
        int la = a.size();
        int lb = b.size();
        int len = min(la,lb);
        string res = "";
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]) return res;
            res.push_back(a[i]);
        }
        return res;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        if(length == 0) return "";
        if(length == 1) return strs[0];
        string res = strs[0];
        for(int i=0;i<length-1;i++){
            res = Prefix(res, strs[i+1]);
            if(res == "") return res;
        }
        return res;
    }
};
