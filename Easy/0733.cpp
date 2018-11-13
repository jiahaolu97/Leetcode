class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int y, int x, int newColor) {   // x,y ∈ [0,w-1] [0,h-1]
        h = image.size();
        w = image[0].size();
        bool visited[h][w];
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
                visited[j][i] = false;
        queue<pair<int,int>> st;
        set<pair<int,int>> change;
        pair<int,int> p;
        p.first = y;
        p.second = x;
        st.push(p);
        change.insert(p);
        int srcColor = image[y][x];
        visited[y][x] = true;
        while(st.size()){
            p = st.front();
            y = p.first;
            x = p.second;
            //cout << y << "," << x << endl;
            st.pop();
            for(int d=0;d<4;d++){
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if(out(nx,ny)) continue;
                //cout << "not out" << endl;
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if(image[ny][nx] != srcColor) continue;
                //cout << "add" << nx << "," << ny << endl;
                pair<int,int> newp;
                newp.first = ny;
                newp.second = nx;
                st.push(newp);
                change.insert(newp);
            }
        }
        //cout << change.size() <<endl;
        vector<vector<int>> res = image;
        for(pair<int,int> p:change){
            res[p.first][p.second] = newColor;
        }
        return res;
    }
    
private:
    int w,h;
    int dir[4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    bool out(int x,int y){
        if(x<0 || x>=w || y<0 || y>=h) return true;
        return false;
    }
    bool out(pair<int,int> p){
        int y = p.first;
        int x = p.second;
        return out(x,y);
    }
};
