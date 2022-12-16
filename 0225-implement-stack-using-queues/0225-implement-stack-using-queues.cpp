class MyStack {
public:
//     queue<int> input;
//     queue<int> output;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         input.push(x);
//     }
    
//     int pop() {
//         if(output.empty()){
//             while(!input.empty()){
//                 output.push(input.front());
//                 input.pop();
//             }
//         }
//         int x = output.front();
//         output.pop();
//         return x;
//     }
    
//     int top() {
//         if(output.empty()){
//             while(!input.empty()){
//                 output.push(input.front());
//                 input.pop();
//             }
//         }
//         int x = output.front();
//         return x;

//     }
    
//     bool empty() {
//         if(input.size() == 0 and output.size() == 0) return 1;
//         return 0;
//     }
    
    
    queue<int> q;
    MyStack() {
    }
    void func(queue<int> &q, int val){
        if(q.empty()){
            q.push(val);
            return;
        }
        int x = q.front();
        // cout << " " << x << endl;
        q.pop();
        func(q, val);
        q.push(x);
    }
    
    void rev(queue<int> &q){
        if(q.empty()){
            return;
        }
        int x = q.front();
        q.pop();
        rev(q);
        q.push(x);
    }
    
    void push(int x) {
        rev(q);
        func(q, x);
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return 1;
        return 0;
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */