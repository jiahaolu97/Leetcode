class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        int pivot = 0;
        vector<int>::iterator it = nums.begin();
        it++;
        for(int i=1;i<nums.size();i++,it++){
            if(nums[i]<nums[i-1]){
                pivot = i;
                break;
            }             
        }
        if(pivot==0){
            int c = bisearch(nums,0,nums.size(),target);
            return c;
        }
        vector<int> a(nums.begin(),it);
        vector<int> b(it,nums.end());
        printVec(a);
        printVec(b);
        int aa = bisearch(a,0,a.size(),target);
        int bb = bisearch(b,0,b.size(),target);
        if(aa!=-1){
            return aa;
        }
        else{
            if(bb!=-1) return a.size()+bb;
        }
        return -1;
    }
    
    int bisearch(vector<int>& nums,int l,int r,int target){
        if(l>r) return -1;
        int m = (l+r)/2;
        if(nums[m]==target) return m;
        if(nums[m]<target){
            return bisearch(nums,m+1,r,target);
        }
        if(nums[m]>target){
            return bisearch(nums,l,m-1,target);
        }
    }
    
    void printVec(vector<int>& a){
        for(int i=0;i<a.size();i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
