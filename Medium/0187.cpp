class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size()<=9)
            return result;
        map<string,int> c;
        
        for(int i=0;i<s.size()-9;i++){
            string tmp = s.substr(i,10);
            // cout << tmp << endl;
            if(c[tmp]!=0){
                if(c[tmp]==1)   result.push_back(tmp);
                c[tmp]++;
            }else{
                // c.insert(pair<string,int>(tmp,1));
                c[tmp] = 1;
            }
        }
        return result;
    }
};
