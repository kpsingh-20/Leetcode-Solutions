class MyCircularDeque {
public:
    
    vector<int> v;
    int k, n;
    MyCircularDeque(int k) {
        v = vector<int>(k, -1);
        this->k = k;
        this->n = 0;
        
    }
    
    bool insertFront(int value) {
        if(n == k) return 0;
        for(int i=n; i>0; i--){
            v[i] = v[i-1];
        }
        v[0] = value;
        n++;
        return 1;
    }
    
    bool insertLast(int value) 
    {
        if(n == k) return 0;
        v[n] = value;
        n++;
        return 1;
    }
    
    bool deleteFront() {
        if(n == 0) return 0;
        for(int i=0; i<n-1; i++){
            v[i] = v[i+1];
        }
        v[n-1] = -1;
        n--;
        return 1;
    }
    
    bool deleteLast() {
        if(n == 0) return 0;
        v[n-1] = -1;
        n--;
        return 1;
    }
    
    int getFront() {
        if(n == 0) return -1;
        return v[0];
    }
    
    int getRear() {
        if(n == 0) return -1;
        return v[n-1];
    }
    
    bool isEmpty() {
        if(n == 0) return 1;
        return 0;
    }
    
    bool isFull() {
        if(n == k)return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */