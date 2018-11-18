class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int nei[N][N];
        bool visited[N];
        int dist[N];
        int curMin = 1e9;
        int minIndex = -1;
        for(int i=0;i<N;i++){
            visited[i] = false;
            dist[i] = 1e9+7;
            for(int j=0;j<N;j++)
                nei[i][j] = -1;
        }
        int s,d,w;
        for(int i=0;i<times.size();i++){
            vector<int> v = times[i];
            s = v[0];
            d = v[1];
            w = v[2];
            nei[s-1][d-1] = w;
        }
                
        s = K-1;
        visited[s] = true;
        dist[s] = 0;
        while(true){
            curMin = 1e9;
            minIndex = -1;
            for(int i=0;i<N;i++){
                if(visited[i]) continue;
                if(nei[s][i] != -1 && dist[s] + nei[s][i] < dist[i]){
                    dist[i] = dist[s] + nei[s][i];
                }
                if(dist[i] < curMin){
                    curMin = dist[i];
                    minIndex = i;
                }
            }
            if(curMin == 1e9) break;
            s = minIndex;
            visited[s] = true;
        }
        int res = 0;
        for(int i=0;i<N;i++){
            if(res < dist[i]) res = dist[i];
            //cout << dist[i] << endl;
        }
        if(res == 1e9+7) return -1;
        return res;
    }
};
