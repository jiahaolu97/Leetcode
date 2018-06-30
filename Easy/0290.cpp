class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.size()!= countSize(str)) return false;
        map<char,string> m;
        map<string,char> im;
        int index = 0;
        for(int i=0;i<pattern.size();i++){
            char c = pattern[i];
            string t = findNext(str,&index);
            cout << t << endl;
            if(t == "NULL"){
                cout << "str short" << endl;
                return false;
            }
            if(i==pattern.size()-1 && index<str.size()){
                cout << "pattern short" << endl;
                return false;
            }
            if(m.count(c)==0){
                if(im.count(t)!=0) return false;
                m[c] = t;
                im[t] = c;
            }else{
                string model = m[c];
                if(model!=t) return false;
            }
        }
        return true;
    }
    string findNext(string s,int* pos){
        if(*pos >= s.size()) return "NULL";
        int len = 0;
        int ori = *pos;
        for(int i=*pos;i<s.size();i++){
            if(s[i]==' ') break;
            len++;        
        }
        (*pos) += (len+1);
        return s.substr(ori,len);
    }
    int countSize(string t){
        int res = 0;
        for(int i=0;i<t.size();i++){
            if(t[i]==' ') res++;
        }
        return res+1;
    }
    
};
