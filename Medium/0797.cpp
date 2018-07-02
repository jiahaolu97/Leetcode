class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        if(graph.size()==0) return res;
        int num = graph.size();
        queue<vector<int>> q;
        vector<int> start;
        start.push_back(0);
        q.push(start);
        while(q.size()){
            vector<int> path = q.front();
            q.pop();
            int last = path[path.size()-1];
            for(int i=0;i<graph[last].size();i++){
                vector<int> line(path);
                int k = graph[last][i];
                line.push_back(k);
                if(k == num-1){
                    res.push_back(line);
                }else
                    q.push(line);
            }
        }
        return res;
    }
};
