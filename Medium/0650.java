class Solution {
    public int minSteps(int n) {
        int res = 0;
        while(n>1){
            boolean flag = true;
            for(int i=2;i<=Math.sqrt(n);i++){
                if(n%i==0){
                    n /= i;
                    
                    res += i;
                    flag = false;
                    break;
                }
            }
            if(flag){
                // System.out.println("in");
                res += n;
                break;
            }
        }
        return res;
    }
}
