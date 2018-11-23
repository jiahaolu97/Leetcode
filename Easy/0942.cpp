class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.size(); // [0, len]
        int max = len;
        int min = 0;
        vector<int> res;
        for(int i=0;i<len;i++){
            if(S[i] == 'I') res.push_back(min++);
            else res.push_back(max--);
        }
        res.push_back(max);
        //cout << max << "," << min << endl;
        return res;
    }
};
