class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()<4) return res;
        int a,b,c,d;
        set<string> s;
        sort(nums.begin(),nums.end());
        for(a=0;a<nums.size()-3;a++){
            for(b=a+1;b<nums.size()-2;b++){
                c = b+1;
                d = nums.size()-1;
                while(c<d){
                    int add = nums[a]+nums[b]+nums[c]+nums[d];
                    if(add == target){
                        string h;
                        h.append(to_string(nums[a]));
                        h.push_back(',');
                        h.append(to_string(nums[b]));
                        h.push_back(',');
                        h.append(to_string(nums[c]));
                        h.push_back(',');
                        h.append(to_string(nums[d]));
    //                    cout << h << endl;
                        if(s.find(h)==s.end()){
                            s.insert(h);
                            vector<int> line;
                            line.push_back(nums[a]);
                            line.push_back(nums[b]);
                            line.push_back(nums[c]);
                            line.push_back(nums[d]);
                            res.push_back(line);
                        }
                        while(nums[c+1]==nums[c]) c++;
                        c++;
                    }else if(add<target){
                        c++;
                    }else{
                        d--;
                    }
                }
            }
        }



        return res;
    }
};
