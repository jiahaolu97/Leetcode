class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > result ;   
        typedef pair<int,int> pos;
        queue<pos > q;
        int height = matrix.size();
        int width = matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            vector<int> temp;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    temp.push_back(-1);
                }else{
                    temp.push_back(0);
                    q.push(make_pair(i,j));
                }
            }
            result.push_back(temp);
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            int val = result[row][col];
            if(row>0 && result[row-1][col] == -1){
                q.push(make_pair(row-1,col));
                result[row-1][col] = val+1;
            }
            if(row<height-1 && result[row+1][col] == -1){
                q.push(make_pair(row+1,col));
                result[row+1][col] = val+1;
            }
            if(col>0 && result[row][col-1] == -1){
                q.push(make_pair(row,col-1));
                result[row][col-1] = val+1;
            }
            if(col<width-1 && result[row][col+1] == -1){
                q.push(make_pair(row,col+1));
                result[row][col+1] = val+1;
            }
        }
        return result;
    }
};
