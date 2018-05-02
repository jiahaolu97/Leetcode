int strStr(char* haystack, char* needle) {
    if(*needle == 0) return 0;
    int idx = 0;
    while(*haystack != 0){
        if(*haystack == *needle){
            int cnt = 0;
            while(haystack[cnt] == needle[cnt]){
                cnt++;
                if(needle[cnt]==0) return idx;
                
            }
        }
        idx++;
        haystack++;
    }
    if(*needle==0) return idx;
    return -1;
}
