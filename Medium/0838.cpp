class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.length();
        char* state = (char*)malloc(len*sizeof(char));
        for(int i=0;i<len;i++) state[i] = 0;
        // int* arr = (int*)malloc(len*sizeof(int));
        int idx = -1;
        int last = 0;
        while(idx++<len){
            if(dominoes[idx]=='.')
                continue;
            if(dominoes[idx]=='L'){
                for(int i=last;i<= idx;i++) state[i] = 'L';
                last = idx;
                continue;
            }
            if(dominoes[idx]=='R'){
                last = idx;
                int i;
                for(i=idx+1;i<len;i++){
                    if(dominoes[i]=='.') continue;
                    if(dominoes[i]=='R'){
                        for(;idx<i;idx++) state[idx] = 'R';
                        idx--;
                        break;
                    }
                    else{//left = idx; right = i;
                        int left = idx;
                        int right = i;
                        while(left<right){
                            state[left++] = 'R';
                            state[right--] = 'L';
                        }
                        last = i;
                        idx = i;
                        break;
                    }
                }
                if(i==len){
                    for(int j=last;j<len;j++)   state[j]='R';
                }
            }
        }
        for(int i=0;i<len;i++){
            if(!state[i])      state[i] = '.';
        }
        string sss(state,len);
        return sss;
    }
};
