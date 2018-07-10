class Solution {
public:
    int countSubstrings(string s) {
        string t;
        int res = 0;
        for(int i=0;i<s.size();i++){
            t.push_back(s[i]);
            for(int j=i;j>=0;j--){
                string tmp = t.substr(j,s.size()-j);
                // cout << tmp << endl;
                if(isPalindro(tmp)){
                    res++;
                    // cout << tmp << endl;
                }
            }
        }
        return res;
    }
    
    bool isPalindro(string s){
        if(s.size()==1 || s.size()==0) return true;
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
