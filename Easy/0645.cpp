class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        int v[len];
        memset(v,0,len*sizeof(int));
        for(int i=0;i<len;i++){
            int val = nums[i];
            v[val-1]++;
        }
        vector<int> res(2,0);
        for(int i=0;i<len;i++){
            if(v[i]==2){
                res[0] = i+1;
            }else if(v[i]==0){
                res[1] = i+1;
            }
        }
        return res;
    }
};
