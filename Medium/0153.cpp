class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int>::iterator it = nums.begin();
        int pivot = 0;
        for(int i=1;i<nums.size();i++,it++){
            if(nums[i]<nums[i-1]){
                pivot = i;
                return nums[i];
            }
        }
        return nums[0];
//         int a = pivot;  // bigger and front
//         int b = nums.size()-pivot;  // smaller and tail
//         int len = nums.size();
//         if(len%2){      // a number
//             int pos = len/2;
//             if(pos+1>b){
//                 return pos-b;
//             }else{
//                 return a+pos;
//             }
//         }else{  // a mid value between two numbers
//             int l = len/2-1;
//             int r = len/2;
            
//         }
    }
};
