class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            string c = ops[i];
            if(c=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }else if(c=="D"){
                int a = st.top();
                st.push(2*a);
            }else if(c=="C"){
                st.pop();
            }
            else{
                int m = stoi(c);
                st.push(m);
            }
        }
        int res = 0;
        while(st.size()>0){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
