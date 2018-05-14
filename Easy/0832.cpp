class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> result;
        for(int i=0;i<A.size();i++){
            vector<int> row = A[i];
            vector<int> rev;
            for(int j=row.size()-1;j>=0;j--){
                int k = row[j]?0:1;
                rev.push_back(k);
            }
            result.push_back(rev);
        }
        return result;
    }
};
