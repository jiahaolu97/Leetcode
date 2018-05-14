int singleNumber(int* nums, int numsSize) {
    int res = 1;
    for(int i=0;i<numsSize;i++){
        res ^= *nums++;
    }
    return res^1;
}
