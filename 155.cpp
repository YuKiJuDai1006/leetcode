class MinStack {
public:
    vector<int> st;
    int size;

    MinStack() {
        size = 0;
    }
    
    void push(int val) {
        st.push_back(val);
        size++;
    }
    
    void pop() {
        st.pop_back();
        size--;
    }
    
    int top() {
        return st[size-1];
    }
    
    int getMin() {
        return *min_element(st.begin(), st.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */