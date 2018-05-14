int missingNumber(int* nums, int numsSize) {
    int res = 1;
    for(int i=0;i<=numsSize;i++){
        res ^= i;
        if(i!=numsSize) res ^= nums[i];
    }
    return res^1;
}
