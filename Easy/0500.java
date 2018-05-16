public class Solution {
    public String[] findWords(String[] words) {
        int idx = 0;
        HashSet<Character> up = new HashSet<Character>();
        HashSet<Character> mid = new HashSet<Character>();
        HashSet<Character> below = new HashSet<Character>();
        char[] UP = {'Q','W','E','R','T','Y','U','I','O','P'};
        char[] MID = {'A','S','D','F','G','H','J','K','L'};
        char[] DOWN = {'Z','X','C','V','B','N','M'};
        for(int i=0;i<UP.length;i++) up.add(UP[i]);
        for(int i=0;i<MID.length;i++) mid.add(MID[i]);
        for(int i=0;i<DOWN.length;i++) below.add(DOWN[i]);
        for(int i=0;i<words.length;i++){
            String s = words[i];
            char[] arr = s.toUpperCase().toCharArray();
            int chose = -1;
            if(up.contains(arr[0])) chose = 0;
            else if(mid.contains(arr[0])) chose = 1;
            else chose = 2;
            boolean isres = true;
            for(int j=1;j<arr.length;j++){
                int k;
                if(up.contains(arr[j])) k = 0;
                else if(mid.contains(arr[j])) k = 1;
                else k = 2;
                if(k!=chose){
                    isres = false;
                    break;
                } 
            }
            if(isres) words[idx++] = s;
        }
        String[] res = new String[idx];
        for(int i=0;i<idx;i++){
            res[i] = words[i];
        }
        return res;
    }
}
