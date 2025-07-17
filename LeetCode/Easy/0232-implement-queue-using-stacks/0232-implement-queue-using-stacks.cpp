class MyQueue {
private:
    stack<int> pushStack;
    stack<int> popStack;

public:
    MyQueue() {

    }
    
    void push(int x) {
        pushStack.push(x);
    }

    int pop() {
        int top;

        if (!popStack.empty()) {
            top = popStack.top();
            popStack.pop();
            return top;
        }

        while (!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }

        top = popStack.top();
        popStack.pop();
        return top;   
    }
    
    int peek() {
        if (!popStack.empty()) return popStack.top();

        while (!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }

        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
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