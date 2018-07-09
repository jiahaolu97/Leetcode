class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size()==0) return 0;
        map<int,int> m;
        for(int i=0;i<wall.size();i++){
            vector<int> line = wall[i];
            int split = 0;
            for(int j=0;j<line.size()-1;j++){
                split += line[j];
                if(m.count(split)==0){
                    m[split] = 1;
                }else{
                    m[split]++;
                }
            }
        }
        map<int,int>::iterator it = m.begin();
        int max = 0;
        for(;it!=m.end();it++){
            // int pos = it->first;
            int gap = it->second;
            if(gap>max){
                max = gap;
            }
        }
        return wall.size()-max;
    }
};
