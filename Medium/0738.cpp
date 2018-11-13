class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int len = str.size();
        int* arr = (int*)malloc(len*sizeof(int));
        for(int i=0;i<len;i++){
            arr[i] = str[i] - '0';
        }
        int id;
        for(id=0;id<len-1;id++){
            if(arr[id]>arr[id+1]) break;
        }
        if(id == len-1) return N;

        arr[id++]--;
        for(;id<len;id++){
            arr[id] = 9;
        }

        int res = 0;
        for(int i=0;i<len;i++){
            res *= 10;
            res += arr[i];
        }
        free(arr);
        
        return monotoneIncreasingDigits(res);
    }
};
