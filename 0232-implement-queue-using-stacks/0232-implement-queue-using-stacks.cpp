class MyQueue {
public:
    stack<int> st;
    
    void func(stack<int> &st, int val)
    {
        if(st.empty()){
            st.push(val);
            return;
        }
        int x = st.top();
        st.pop();
        func(st, val);
        st.push(x);
    }
    
    MyQueue() {
        st;
    }
    
    void push(int x) {
        func(st, x);
    }
    
    int pop() {
        int ele = st.top();
        st.pop();
        return ele;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.empty()){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */