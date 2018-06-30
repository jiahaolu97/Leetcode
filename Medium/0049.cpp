class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        if(strs.size()==0) return output;
        map<string,int> m;
        int index = 0;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            int len = s.size();
            if(len==0){
                if(m.count(s)==0){
                    m[s] = index++;
                    vector<string> line;
                    line.push_back(s);
                    output.push_back(line);
                }
                else{
                    int pos = m[s];
                    output[pos].push_back(s);
                }
                continue;
            }
            char c[len];
            for(int j=0;j<len;j++){
                c[j] = s[j];
            }
            sort(c,c+len);
            string t;
            for(int j=0;j<len;j++){
                t.push_back(c[j]);
            }
            if(m.count(t)==0){
                m[t] = index++;
                vector<string> line;
                line.push_back(s);
                output.push_back(line);
            }else{
                int pos = m[t];
                output[pos].push_back(s);
            }
        }
        return output;
    }
};
