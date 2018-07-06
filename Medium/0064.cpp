class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> acc;
        int h = grid.size();
        if(h==0) return 0;
        int w = grid[0].size();
        if(w==0) return 0;
        for(int i=0;i<grid.size();i++){
            vector<int> line(grid[0].size(),0);
            acc.push_back(line);
        }
        acc[0][0] = grid[0][0];
        for(int i=1;i<h+w-1;i++){
            int x = i>w-1?w-1:i;
            int y = i>w-1?(i-w+1):0;
            // cout << x << "," << y << endl;
            while(x>=0 && y<=h-1){
                int up,left;
                if(y==0) up = 1e9;
                else up = acc[y-1][x];
                if(x==0) left = 1e9;
                else left = acc[y][x-1];
                acc[y][x] = left>up?up:left;
                acc[y][x] += grid[y][x];
                x--;
                y++;
            }
        }
        // for(int i=0;i<w;i++){
        //     for(int j=0;j<h;j++){
        //         cout << acc[j][i] << " ";
        //     }
        //     cout << endl;
        // }
        return acc[h-1][w-1];
    }
    
};
