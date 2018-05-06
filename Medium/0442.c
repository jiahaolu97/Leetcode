/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
  for(int i=0;i<numsSize;i++){
    	int pos = nums[i]%numsSize;
    	nums[pos] += numsSize;
	}
	int *res = (int*)(malloc(numsSize/2*sizeof(int)));
	int idx = 0;
	for(int i=0;i<numsSize;i++){
		if(nums[i]>2*numsSize){
			int temp = i==0?numsSize:i;
			res[idx++] = temp;
		}
	}
	*returnSize = idx;
	return res;
}
