class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        lastPush = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        A.push(x);
        lastPush = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //cout << "A:" << A.size() << ",B:" << B.size();
        while(A.size()>1){
            B.push(A.front());
            A.pop();
        }
        int val = A.front();
        A.pop();
        if(B.size()==0){
            return val;
        }
        while(B.size()>1){
            A.push(B.front());
            B.pop();
        }
        lastPush = B.front();
        A.push(B.front());
        B.pop();
        //cout << A.size() << endl;
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return lastPush;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(A.size()<=0) return true;
        return false;
    }
private:
    queue<int> A;
    queue<int> B;
    int lastPush;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
