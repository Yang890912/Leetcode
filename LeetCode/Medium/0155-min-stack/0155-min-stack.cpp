class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    int currMin;

    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        if (val <= currMin) {
            minSt.push(val);
            currMin = val;
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
        if (minSt.empty()) currMin = INT_MAX;
        else currMin = minSt.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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