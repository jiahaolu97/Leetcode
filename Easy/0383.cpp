class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int * alphabet = (int*)malloc(26*sizeof(int));
        for(int i=0;i<26;i++) alphabet[i] = 0;
        for(int i=0;i<magazine.length();i++){
            char c = magazine[i];
            int pos = (int)(c-'a');
            alphabet[pos]++;
        }
        for(int j=0;j<ransomNote.length();j++){
            char c = ransomNote[j];
            int pos = (int)(c-'a');
            alphabet[pos]--;
            if(alphabet[pos]<0) return false;
        }
        return true;
    }
};
