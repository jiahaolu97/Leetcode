char findTheDifference(char* s, char* t) {
    int alp[26];
    for(int i=0;i<26;i++){
        alp[i] = 0;
    }
    while(*s){
        int idx = (*s++)-'a';
        alp[idx]++;
    }
    while(*t){
        int idx = (*t++)-'a';
        alp[idx]--;
        if(alp[idx]==-1) return ('a'+idx);
    }
    return 'a';
}
