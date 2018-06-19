class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int head = 0;
        int tail = 1;
        int last = nums[0];
        bool same = false;
        for(;tail<nums.size();tail++){
            int t = nums[tail];
            if(t==last){
                if(same)    continue;
                else{
                    head++;
                    nums[head] = t;
                }
                same = true;
            }else{
                head++;
                nums[head] = t; 
                same = false;
            }
            last = t;
        }
        return head+1;
    }
};
