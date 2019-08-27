class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len==0 || len==1) return;
        int i;
        int tmp;
        for(i = len-1; i>0; i--){
            if(nums[i-1] < nums[i]) break;
        }
        if(i==0){
            for(int j=0; j<len/2; j++){
                tmp = nums[len-j-1];
                nums[len-j-1] = nums[j];
                nums[j] = tmp;
            }
        }else{
            int k;
            for(k=len-1;k>=i;k--){
                if(nums[k]>nums[i-1]) break;
            }
            tmp = nums[k];
            nums[k] = nums[i-1];
            nums[i-1] = tmp;
            for(int j=0;j<(len-i)/2;j++){
                tmp = nums[len-j-1];
                nums[len-j-1] = nums[i+j];
                nums[i+j] = tmp;
            }
        }
    }
};
