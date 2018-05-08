int numJewelsInStones(char* J, char* S) {
    char* jew = J;
    int cnt = 0;
    while(*S){
        while(*jew){
            if(*jew++ == *S){
                cnt++;
                break;
            }
        }
        jew = J;
        S++;
    }
    return cnt;
}
