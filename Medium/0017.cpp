class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        queue<string> q;
        vector<vector<char> >table;
        vector<char> num[9];
        int alphaLen[] = {0,3,3,3,3,3,4,3,4};
        int alphaIdx = 0;
        for(int i=0;i<9;i++){
            int addIdx = alphaLen[i];
            while(addIdx--){
                //cout << (char)('a'+alphaIdx) << endl;
                num[i].push_back((char)('a'+alphaIdx));
                alphaIdx++;
            }
            table.push_back(num[i]);
        }
        int lastLayerLen = 0;
        int curLayerLen = 0;
        for(int i=0;i<digits.size();i++){
            char c = digits[i];
            int v = (int)(c-'0') - 1;
            if(i==0){
                for(int j=0;j<table[v].size();j++){
                    string row;
                    row.push_back(table[v][j]);
                    q.push(row);
                    cout << "first:  " << row << endl;
                    //curLayerLen++;
                    lastLayerLen++;
                }
            }else{
                while(lastLayerLen--){
                    string row = q.front();
                    q.pop();
                    for(int j=0;j<table[v].size();j++){
                        string copyS = row;
                        copyS.push_back(table[v][j]);
                        q.push(copyS);

                        curLayerLen++;
                    }
                }
                lastLayerLen = curLayerLen;
                curLayerLen = 0;
            }
        }
        while(q.size()>0){
            res.push_back(q.front());
    //        cout << q.front() << endl;
            q.pop();
        }
        return res;
    }
};
