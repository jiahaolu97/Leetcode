class Solution {
public:
    bool sd(int num){
        if(num==10000) return false;
        if(num<10) return true;
        if(num<100){
            if(num%10) return true;
            return false;
        }
        if(num%10) return sd(num/10);
        return false;
    }

    bool OK(int o){
        int tmp = o;
        int k = tmp%10;
        while(tmp>0){
            if(o%k) return false;
            tmp = tmp/10;
            k = tmp%10;
        }
        return true;
    }


    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        for(int i=left;i<=right;i++){
            if(sd(i)){
                if(OK(i)){
                    // printf("%d\n",i);
                    vec.push_back(i);
                }

            } 
        }
        return vec;
    }
};
