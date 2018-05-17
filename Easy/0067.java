public class Solution {
    public String addBinary(String A, String B) {
        char a[] = A.toCharArray();
        char b[] = B.toCharArray();
        int maxlen = a.length>b.length?a.length:b.length;
        char c[] = new char[maxlen+1];
        int go = 0;
        int adx = a.length-1;
        int bdx = b.length-1;
        for(int i=maxlen;i>=0;i--){
            int ai = adx<0?0:a[adx] - '0';
            int bi = bdx<0?0:b[bdx] - '0';
            adx--;
            bdx--;
            int v = ai+bi+go;
            if(v<2){
                go = 0;
                c[i] = (char)(v+'0');
            }else{
                go = v/2;
                c[i] = (char)((v%2)+'0');
            }
        }
        StringBuffer sb = new StringBuffer();
        if(c[0]!='0') sb.append(c[0]);
        for(int i=1;i<c.length;i++){
            sb.append(c[i]);
        }
        return sb.toString();
    }

}
