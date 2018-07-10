class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(cost.size()==0) return 0;
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return min(cost[0],cost[1]);
        vector<int> acc(cost.size(),0);
        acc[0] = cost[0];
        acc[1] = cost[1];
        for(int i=2;i<cost.size();i++){
            acc[i] = min(acc[i-2],acc[i-1]) + cost[i];
        }
        for(int i=0;i<cost.size();i++)
            cout << acc[i] << " ";
        return min(acc[len-1],acc[len-2]);
    }
};
