class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool negative = (dividend < 0) ^ (divisor < 0);
        int a = dividend, b = divisor;
        if(a > 0) a = -a; // abs() may lead to overflow
        if(b > 0) b = -b;
        
        int sz = 1, ans = 0, f[32] = {b};
        for(; b >= (INT_MIN>>1); sz++){
            b += b;
            f[sz] = b;
        }
        for(int i = sz - 1; i >= 0; --i){
            if(f[i] >= a){
                ans |= (1 << i);
                a -= f[i];
            }
        }
        
        return negative ? -ans : ans;
    }
};
