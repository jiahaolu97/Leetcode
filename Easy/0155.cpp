class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    map<int,int> m;
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if(m.count(x)==0){
            m[x] = 1;
        }else{
            m[x]++;
        }
    }
    
    void pop() {
        int x = st.top();
        st.pop();
        if(m[x]>1)  m[x]--;
        else m.erase(x);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
