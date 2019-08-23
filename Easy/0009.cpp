class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        vector<int> v;
        int o = x;
        while(x>0){
            v.push_back(x%10);
            x/=10;
        }
        long res = 0;
        for(int i=0;i<v.size();i++){
            res += v[i];
            if(i!=v.size()-1) res *= 10;
        }
        return (res==o);
    }
};
