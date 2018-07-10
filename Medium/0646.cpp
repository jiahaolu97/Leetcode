class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()<=1) return pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        vector<vector<int>> chain;
        chain.push_back(pairs[0]);
        int e = chain[0][1];
        // cout << e << endl;
        for(int i=1;i<pairs.size();i++){
            if(e<pairs[i][0]){
                chain.push_back(pairs[i]);
                e = pairs[i][1];
                // cout << e << endl;
            }
        }
        return chain.size();
    }
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
};
