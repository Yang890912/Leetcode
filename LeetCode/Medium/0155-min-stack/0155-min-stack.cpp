class MinStack {
public:
    int minimum;
    stack<int> MyStack;
    stack<int> MinNumStack;

    MinStack() {
        minimum = INT_MAX;
    }
    
    void push(int val) {
        MyStack.push(val);
        if (val <= minimum) {
            MinNumStack.push(minimum);
            minimum = val;
        }
    }
    
    void pop() {
        int num = MyStack.top();
        if (num == minimum) {
            minimum = MinNumStack.top();
            MinNumStack.pop();
        }
        MyStack.pop();
    }
    
    int top() {
        return MyStack.top();
    }
    
    int getMin() {
        return minimum;
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