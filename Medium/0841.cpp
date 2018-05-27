class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        bool visit[len];
        for(int i=0;i<len;i++){
            visit[i] = false;
        }
        visit[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int val = q.front();
            q.pop();
            vector<int> v = rooms[val];
            for(int i=0;i<v.size();i++){
                if(!visit[v[i]]){
                    q.push(v[i]);
                    visit[v[i]] = true;
                }
            }
        }
        for(int i=0;i<len;i++){
            if(!visit[i]) return false;
        }
        return true;
    }
};
