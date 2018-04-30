/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int * res = (int*)malloc(2*sizeof(int));
    for(int i=0;i<numsSize-1;i++){
        int find = 0;
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                res[0] = i;
                res[1] = j;
                find = 1;
                break;
            }
        }
        if(find) break;
    }
    return res;
}
