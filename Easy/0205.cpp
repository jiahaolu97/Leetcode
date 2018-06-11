class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.size() == 0) return true;
        int idx = 0;
        unordered_map<char,char> umap;
        set<char> usedVal;
        while(idx < s.size()){
            char ss = s[idx];
            char tt = t[idx++];
    //        cout << "t:" << tt << endl;
            if(umap.count(ss) == 0){
                if(usedVal.count(tt)!=0) return false;
                umap[ss] = tt;
                usedVal.insert(tt);
            }else{
                char des = umap[ss];
    //            cout << des << endl;
                if(des != tt) return false;
            }
        }
        return true;
    }
};
