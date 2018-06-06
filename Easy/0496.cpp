// Pay attention to the use of Map   
// just use map[key] = value to insert a new pair
// use map.count(key) == 0 to check if a map contains key;
// use map[key] to get the value corresponding to the key

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> m;
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(s.size()>0 && nums[i]>s.top()){
                //m.insert(pair<int,int>(s.top(),nums[i]));
                m[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        for(int i=0;i<findNums.size();i++){
            // if(m.find(findNums[i])!= m.end()){
            //     int val = m.find(findNums[i])->second;
            //     findNums[i] = val;
            // }else{
            //     findNums[i] = -1;
            // }
            findNums[i] = m.count(findNums[i]) ? m[findNums[i]] : -1;
        }
        return findNums;
    }
};
