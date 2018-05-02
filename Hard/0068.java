class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> res = new ArrayList<String>();
        int idx = 0;	
        int cnt = 0;	
        int cur = 0;
        StringBuffer line = new StringBuffer();
        while(idx<words.length){
        	boolean end = false;
        	while(cur+cnt-1<=maxWidth){
        		if(idx+cnt>=words.length){
        			end = true;
        			break;
        		}
        		cur += words[idx+cnt].length();
        		cnt++;
        	}
        	if(!end){
            	for(int i=idx;i<cnt+idx-1;i++){
            		line.append(words[i]);
            		if(i!=cnt+idx-2)
            			line.append(" ");
            	}
            	idx = cnt+idx-1;
            	int k = maxWidth - line.length();
            	if(cnt == 2){
            		for(int i=0;i<k;i++){
            			line.append(" ");
            		}
            	}else{
            		int white[] = new int[cnt-2];
            		int seek = 0;
            		while(k>0){
            			white[seek++]++;
            			k--;
            			if(seek == white.length) seek = 0;
            		}
            		String[] mat = line.toString().split(" ");
            		line = new StringBuffer();
            		for(int i=0;i<mat.length;i++){
            			line.append(mat[i]);
            			if(i!=mat.length-1){
            				for(int j=0;j<=white[i];j++){
            					line.append(" ");
            				}
            			}
            		}
            	}

            	res.add(line.toString());
//            	System.out.println(line);
            	line = new StringBuffer();
            	cur = 0;
            	cnt = 0;
        	}
        	else{
        		for(int i=idx;i<words.length;i++){
        			line.append(words[i]);
                    if(i!=words.length-1)
        			    line.append(" ");
        		}
        		int k = maxWidth - line.length();
        		for(int i=0;i<k;i++){
        			line.append(" ");
        		}
        		res.add(line.toString());
        		break;
        	}
        }
        return res;
    }
}
