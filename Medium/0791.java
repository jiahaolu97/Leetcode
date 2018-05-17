class Solution {
    public String customSortString(String S, String T) {
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        HashMap<Integer,Character> imap = new HashMap<Integer,Character>();
        for(int i=0;i<26;i++){
            map.put((char)('a'+i),26+i);
            imap.put(26+i,(char)('a'+i));
        }
        char[] srr = S.toCharArray();
        for(int i=0;i<srr.length;i++){
            map.put(srr[i],i);
            imap.put(i,srr[i]);
        }
        char[] trr = T.toCharArray();
        int[] res = new int[T.length()];
        for(int i=0;i<trr.length;i++){
            int k = map.get(trr[i]);
            res[i] = k;
        }
        Arrays.sort(res);
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<trr.length;i++){
            sb.append(imap.get(res[i]));
        }
        return sb.toString();
    }
}
