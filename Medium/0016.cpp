class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int l,m,r;
        int res = 0;
        int diff = 1e8;
        for(l=0;l<nums.size()-2;l++){
            m = l+1;
            r = nums.size()-1;
            int t = target - nums[l];
            while(m<r){
                int val = nums[m]+nums[r]-t;
                if(abs(val)<diff){
                    res = val + target;
                    diff = abs(val);
                }
                if(val>0) r--;
                else if(val<0) m++;
                else return target;
            }
        }
        return res;
    }
};
