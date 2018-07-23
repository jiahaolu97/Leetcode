class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result;
        if(M.size()==0 || M[0].size()==0) return result;
        for(int i=0;i<M.size();i++){
            vector<int> line;
            for(int j=0;j<M[0].size();j++){
                int add = M[i][j];
                int w = 1;
                if(i!=0){
                    add += M[i-1][j];
                    w++;
                    if(j!=0){
                        add += M[i-1][j-1]; w++;
                    }
                    if(j!=M[0].size()-1){
                        add += M[i-1][j+1]; w++;
                    }
                }
                if(i!=M.size()-1){
                    add += M[i+1][j];
                    w++;
                    if(j!=0){
                        add += M[i+1][j-1]; w++;
                    }
                    if(j!=M[0].size()-1){
                        add += M[i+1][j+1]; w++;
                    }
                }
                if(j!=0){
                    add += M[i][j-1];w++;
                }
                if(j!=M[0].size()-1){
                    add += M[i][j+1];w++;
                }
                int n = add/w;
                line.push_back(n);
            }
            result.push_back(line);
        }
        return result;
    }
};
