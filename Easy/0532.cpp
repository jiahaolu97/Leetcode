class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int last = 1e8;
        int far = 1;
        int res = 0;
        for(int i=0;i<nums.size()-1;i++){
            int c = nums[i];
            if(c==last) continue;
            last = c;
            while(far<=i) far++;
            while(far<nums.size() && nums[far]-c<k){
                far++;
            }
            
            if(far == nums.size()) return res;
            if(nums[far]-c == k){
                cout << nums[i] << "," << nums[far] << endl;
                res ++;
            }
            else continue;
        }
        return res;
    }
};
