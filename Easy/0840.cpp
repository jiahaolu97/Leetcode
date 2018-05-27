class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        if(row<3 || col<3) return 0;
        int*rec = (int*)malloc(9*sizeof(int));
        for(int i=0;i<row-2;i++){
            for(int j=0;j<row-2;j++){
                memset(rec,0,9*sizeof(int));
                bool magic = true;
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        int val = grid[a][b];
                        if(val==0 || val>9){
                            magic = false;
                            break;
                        }
                        else if(--rec[val-1] == -2){
                            magic = false;
                            break;
                        }
                    }
                    if(!magic) break;
                }
                if(magic){
                    if(grid[i][j]+grid[i][j+1]+grid[i][j+2]!=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] 
                        || grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]) continue;
                    if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]
                        || grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]) continue;
                    if(grid[i][j]+grid[i+2][j+2]!=grid[i][j+2]+grid[i+2][j]) continue;
                    res++;			
                }
            }
        }
        return res;
    }
};
