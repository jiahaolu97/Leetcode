class Solution {
public:
    bool valid(char c){
        if(c>='0'&&c<='9') return true;
        if(c>='a'&&c<='z') return true;
        if(c>='A'&&c<='Z') return true;
        return false;
    }
    bool equal(char a,char b){
        if(a>='0'&&a<='9' && a==b) return true;
        if(a>='a'&&a<='z'){
            if(b==a || a==b-'A'+'a') return true;
        }
        if(a>='A'&&a<='Z'){
            if(b==a || a==b-'a'+'A') return true;
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        int head = 0;
        int tail = s.size()-1;
        while(head<tail){
            while(!valid(s[head])){
                head++;
                if(head>=tail) return true;
            }
            while(!valid(s[tail])){
                tail--;
                if(tail<=head) return true;
            }
            if(equal(s[head],s[tail])){
                head++;
                tail--;
                continue;
            }
            else return false;
        }
        return true;
    }
};
