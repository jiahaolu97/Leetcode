class Solution {
public:
    typedef pair<int,int> p;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        h = grid.size();
        w = grid[0].size();
        int res = 0;
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(grid[y][x] == 0 || grid[y][x] > 1) continue;
                queue<pair<int,int>> q;
                q.push(make_pair(y,x));
                int cur = 1;
                while(q.size()){
                    p pp = q.front();
                    q.pop();
                    int sy = pp.first;
                    int sx = pp.second;
                    //cout << sy << "," << sx << endl;
                    grid[sy][sx] ++;
                    for(int d=0;d<4;d++){
                        int ny = sy + dir[d][0];
                        int nx = sx + dir[d][1];
                        if(out(ny,nx)) continue;
                        if(grid[ny][nx] == 1){
                            q.push(make_pair(ny,nx));
                            grid[ny][nx]++;
                            cur++;
                        }
                    }
                }
                if(cur>res) res = cur;
            }
        }
        return res;
    }
    

    
    
private:
    int w, h;
    int dir[4][2] = {
        {0,1},{0,-1},{1,0},{-1,0}  
    };
    // x y start from 0
    int index(int y,int x){
        return y*w + x;
    }
    bool out(int y,int x){
        if(x<0 || x>=w || y<0 || y>=h) return true;
        return false;
    }
    bool out(pair<int,int> e){
        return out(e.first, e.second);
    }
};
