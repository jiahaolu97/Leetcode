class Solution {
public:
    string longestWord(vector<string>& words) {
        string result;
        if(words.size()==0) return result;
        sort(words.begin(),words.end());
        for(int i=words.size()-1;i>=0;i--){
            string s = words[i];
            if(s.size()<result.size()) continue;
            int k = search(words,s,0,words.size()-1);
            if(k==-1) continue;
            if(check(words,s,k)){
                result = s;
            }
        }
        return result;
    }
    
    bool check(vector<string>& words,string w,int k){
        int len = w.size();
        if(len==1) return true;
        string next(w,0,len-1);
        int n = search(words,next,0,k);
        if(n==-1) return false;
        return check(words,next,n);
    }
    
    
    int search(vector<string>& words,string w,int s,int e){
        if(s>e) return -1;
        int m = (s+e)/2;
        if(words[m]==w) return m;
        if(words[m]<w){
            return search(words,w,m+1,e);
        }
        return search(words,w,s,m-1);
    }
};
