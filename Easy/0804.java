class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<String> set = new HashSet<String>();
        for(int i=0;i<words.length;i++){
            String w = words[i];
            StringBuffer sb = new StringBuffer();
            for(int j=0;j<w.length();j++){
                int idx = (int)(words[i].charAt(j)-'a');
                sb.append(morse[idx]);
            }
            set.add(sb.toString());
        }
        return set.size();
        
    }
}
