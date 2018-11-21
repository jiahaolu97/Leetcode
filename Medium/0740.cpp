class Solution {
public:
    int max(int a,int b){
        // cout << "a = " << a << ", b = " << b << endl;
        return a>b?a:b;
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;     // < value, sum >
        int val,sum = 0;
        for(int i=0;i<nums.size();i++){
            val = nums[i];
            if(m.count(val) == 0) m[val] = nums[i];
            else m[val] += val;
        }
        int end = 10001;
        int* arr = new int[end];
        memset(arr,0,end * sizeof(int));
        for(pair<int,int> p : m){
            arr[p.first] = p.second;
        }
        // for(int i=0;i<end;i++){
        //                 cout << arr[i] << ", ";
        // }
        for(int i=0;i<end;i++){
            if(arr[i] == 0) continue;
            int j = i;
            while(j < end && arr[j]) j++;
            // [i,j-1] a filled subarray
            if(i == j-1) sum += arr[i];     //only one element
            else if(i == j-2){              //two elements
                sum += max(arr[i],arr[i+1]);
            }else if(i == j-3){             //3 elements
                sum += max(arr[i] + arr[i+2] , arr[i+1]);
            }
            else{
                int* dp = new int[j-i];
                memset(dp,0,sizeof(int) * (j-i));
                int it = i;
                dp[0] = arr[it++];
                dp[1] = arr[it++];
                dp[2] = dp[0] + arr[it];
                it ++;
                for(;it < j;it++){
                    dp[it - i] = max(dp[it - i - 2], dp[it - i - 3]) + arr[it];
                }
                sum += max( dp[j-i-1] , dp[j-i-2]);
                delete[] dp;
            }
            i = j;
        }
        delete[] arr;
        return sum;
    }
};
