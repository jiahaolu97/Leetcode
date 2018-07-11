class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0)return 0;
        Arrays.sort(points,new Comparator<int[]>(){
           public int compare(int[] o1,int[] o2){
               if(o1[0]==o2[0]){
                   return o1[1]-o2[1];
               }
               return o1[0]-o2[0];
           } 
        });
        int curend = points[0][1];
        int cnt = 1;
        int pos = 1;
        for(;pos<points.length;pos++){
            if(points[pos][0]>curend){
                curend = points[pos][1];
                cnt++;
            }else{
                curend = Math.min(curend,points[pos][1]);
            }
        }
        return cnt;
    }
}
