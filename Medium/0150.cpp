class Solution {
public:
    bool isToken(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            return true;
        }
        return false;
    }
    int str2int(string s){
        int res = 0;
        if(s[0] == '-'){
            for(int i=1;i<s.size();i++){
                int v = (int)(s[i] - '0');
                res *= 10;
                res -= v;
            }
        }else{
            int i = 0;
            for(;i<s.size();i++){
                int v = (int)(s[i] - '0');
                res *= 10;
                res += v;
            }
        }
        return res;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(isToken(tokens[i])){
                string str = tokens[i]; 
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int r;
                if(str =="+")  r = a+b;
                else if(str =="-") r = a-b;
                else if(str =="*") r = a*b;
                else r = a/b;
                s.push(r);
            }else{
                int value = str2int(tokens[i]);
                s.push(value);
            }
        }
        return s.top();
    }
};
