class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 1;
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};
