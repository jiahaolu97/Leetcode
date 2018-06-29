class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int num = 1;
        int i;
        for(i=citations.size()-1;i>=0;i--){
            if(citations[i]<num)    break;
            num++;
        }
        return num-1;
    }
};
