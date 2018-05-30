class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 0) return res;
        sort(nums.begin(),nums.end());
        set<string> s;
        int l,r,m;
        for(l=0;l<nums.size()-2;l++){
            if(nums[l]>0) return res;
            int target = 0-nums[l];
            m = l+1;
            r = nums.size()-1;
            while(m<r){
                if(nums[m]+nums[r]<target) m++;
                else if(nums[m]+nums[r]>target) r--;
                else{
                    string h;
                    h.append(to_string(nums[l]));
                    h.push_back(',');
                    h.append(to_string(nums[m]));
                    h.push_back(',');
                    h.append(to_string(nums[r]));
                    if(s.find(h)==s.end()){
                        vector<int> vec;
                        vec.push_back(nums[l]);
                        vec.push_back(nums[m]);
                        vec.push_back(nums[r]);
                        res.push_back(vec);
                        s.insert(h);
                    }
                    while(m<nums.size()-1 && nums[m+1]==nums[m]) m++;
                    m++;
                }
            }
        }
        return res;
    }
};
