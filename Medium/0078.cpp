class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len == 0) return res;
        vector<string> vec;
        string str;
        for(int i=0;i<len;i++){
            str.push_back('0');
        }
        vec.push_back(str);
        int pos = 0;
        int cursize = 1;
        for(;pos<len;pos++){
            for(int j=0;j<cursize;j++){
                str.clear();
                str = vec[j];
                str[pos] = '1';
                vec.push_back(str);
            }
            cursize*=2;
        }
        for(int i=0;i<vec.size();i++){
            vector<int> line;
            string s = vec[i];
            for(int j=0;j<len;j++){
                if(s[j]=='1'){
                    line.push_back(nums[j]);
                }
            }
            res.push_back(line);
        }
        return res;
    }
};
