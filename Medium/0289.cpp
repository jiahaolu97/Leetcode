class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> neighbors;
        for(int i=0;i<board.size();i++){
            vector<int> line;
            int cur;
            for(int j=0;j<board[0].size();j++){
                cur = 0;
                if(j!=0 && board[i][j-1]) cur++;
                if(i!=0 && board[i-1][j]) cur++;
                if(j!=board[0].size()-1 && board[i][j+1]) cur++;
                if(i!=board.size()-1 && board[i+1][j]) cur++;
                if(j!=0 && i!=0 && board[i-1][j-1]) cur++;
                if(j!=0 && i!=board.size()-1 && board[i+1][j-1]) cur++;
                if(j!=board[0].size()-1 && i!=board.size()-1 && board[i+1][j+1]) cur++;
                if(j!=board[0].size()-1 && i!=0 && board[i-1][j+1]) cur++;
                line.push_back(cur);
            }
            neighbors.push_back(line);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]){
                    if(neighbors[i][j]<2 || neighbors[i][j]>3)
                        board[i][j] = 0;
                }else{
                    if(neighbors[i][j] == 3)
                        board[i][j] = 1;
                }
            }
        }
        return;
    }
};
