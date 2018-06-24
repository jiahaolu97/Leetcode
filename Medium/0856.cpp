class Solution {
public:
    bool isNum(string S){
        if(S[0]>='0' && S[0]<='9')  return true;
        return false;
    }
    
    int scoreOfParentheses(string S) {
        if(S.size()==0) return 0;
        stack<string> s;
        int idx = 0;
        while(idx<S.size()){
            char c = S[idx];
            if(c=='('){
                string tmp;
                tmp.push_back(c);
                s.push(tmp);
            }else{  // push")"
                if(s.top() != "("){ // top = num 
                    int p = 0;
                    while(s.size() && isNum(s.top())){
                        string t = s.top();
                        p += stoi(t);
                        s.pop();
                    }
                    s.pop();
                    p *= 2;
                    s.push(to_string(p));
                }else{  //  top == (
                    s.pop();
                    int p = 1;
                    while(s.size() && isNum(s.top()) ){
                        string t = s.top();
                        p += stoi(t);
                        s.pop();
                    }
                    s.push(to_string(p));
                }
            }
            idx++;
        }
        int res = 0;
        while(s.size() && isNum(s.top())){
            string t = s.top();
            res += stoi(t);
            s.pop();
        }
        return res;
    }
};
