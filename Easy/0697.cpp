class Solution {
public:
    typedef struct ele{
        //int num;
        int fre;
        int s;
        int e;
    }ele;
    // <
    static bool comp(ele e1,ele e2){
        if(e1.fre == e2.fre)    return e1.e-e1.s > e2.e-e2.s; 
        return e1.fre < e2.fre;
    }
    int findShortestSubArray(vector<int>& nums) {
        map<int,ele> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]) == 0){
                ele e;
                //e.num = nums[i];
                e.fre = 1;
                e.s = i;
                e.e = i;
                m[nums[i]] = e;
            }else{
                m[nums[i]].e = i;
                m[nums[i]].fre ++;
            }
        }
        vector<ele> v;
        for(pair<int,ele> p : m){
            v.push_back(p.second);
        }
        sort(v.begin(),v.end(),comp);
        ele max = v[v.size()-1];
        return max.e - max.s + 1;
    }
};
