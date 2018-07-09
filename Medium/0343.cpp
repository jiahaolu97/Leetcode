class Solution {
public:
    int integerBreak(int n) {
        int arr[n+1];
        memset(arr,0,(n+1)*sizeof(int));
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2;i<=n;i++){
            int half = i/2;
            arr[i] = max(arr[half]*arr[i-half],arr[half-1]*arr[i-half+1]);
            if(i!=n){
                arr[i] = max(i,arr[i]);
            }
        }
        return arr[n];
    }
};
