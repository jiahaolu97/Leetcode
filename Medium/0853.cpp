class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0)  return 0;
        map<int,int> m;
        for(int i=0;i<position.size();i++){
            if(m.count(position[i])==0){
                m[position[i]] = speed[i];
            }else{
                int ori = m[position[i]];
                m[position[i]] = ori>speed[i]?ori:speed[i];
            }
        }
        position.clear();
        speed.clear();
        map<int,int>::iterator iter = m.begin();
        vector<double> pos;
        while(iter!=m.end()){
            pos.push_back((double)(iter->first));
            speed.push_back(iter->second);
            cout << pos[pos.size()-1] <<"," << speed[pos.size()-1] << " " ;
            iter++;
        }
        cout << endl;
        int len = pos.size();
        double time = (double)(target-pos[len-1])/(double)speed[len-1];
        int fleet = 1;
        for(int i=len-2;i>=0;i--){
            double t = (target-pos[i])/speed[i];
            if(t>time){
                fleet++;
                time = t;
            }
        }
        return fleet;
    }
};
