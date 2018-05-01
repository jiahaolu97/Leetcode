class Solution {
    public int myAtoi(String str) {
    	int res = 0;
        str = str.trim();
        if(str.length() == 0) return 0;
        if(!isValid(str.charAt(0))){
        	return 0;
        }
        int index = 1;
        StringBuffer buf = new StringBuffer(String.valueOf(str.charAt(0)));
        while(index<str.length()&&Character.isDigit(str.charAt(index))){
        	buf.append(str.charAt(index++));
        }
        try{
        	res = Integer.parseInt(buf.toString());
        }catch(Exception e){
        	if(buf.charAt(0)=='-' && buf.length()>1) return Integer.MIN_VALUE;
        	if(buf.charAt(0)=='+'&& buf.length()>1) return Integer.MAX_VALUE;
            if(buf.length() == 1) return 0;
        	return Integer.MAX_VALUE;
        }
        return res;
    }
    public boolean isValid(char c){
    	if(c=='-'||c=='+') return true;
    	if(c<='9'&&c>='0') return true;
    	return false;
    }
}
