class Solution {
public:
    int val(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return -1;
    }
    
    int romanToInt(string s) {
        int len = s.size();
        if(len==1) return val(s[0]);
        int res = 0;
        int i = 0;
        for(i=0;i<len-1;i++){
            int cur = val(s[i]);
            int next = val(s[i+1]);
            if(cur>=next){
                res += cur;
            }
            else{
                res += (next - cur);
                i++;
            }
        }
        if(i==len-1) res += val(s[i]);
        return res;
    }
};
