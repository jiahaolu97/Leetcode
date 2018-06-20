class Solution {
public:
    vector<vector<int>> state;
    int h,w;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        h = matrix.size();
        w = matrix[0].size();
        state.resize(matrix.size());
        for(int i=0;i<h;i++){
            // vector<int> line(w,0);
            // state.push_back(line);
            state[i].resize(matrix[0].size());
        }
        int res = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!state[i][j]) {
                    int k = dfs(matrix,state,i,j);
                    if(k>res)   res = k;
                }
                    
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& state,int y,int x){
        if(state[y][x]) return state[y][x];
        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        int candidate = 0;
        for(int i=0;i<4;i++){
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            if(out(dy,dx)) continue;
            if(matrix[dy][dx] <= matrix[y][x]) continue;
            state[dy][dx] = dfs(matrix,state,dy,dx);
            if(state[dy][dx]>candidate) candidate = state[dy][dx];
        }
        state[y][x] = ++candidate;
        return candidate;
    }
    
    bool out(int y,int x){
        if(y<0 || y>=h) return true;
        if(x<0 || x>=w) return true;
        return false;
    }
    
};
