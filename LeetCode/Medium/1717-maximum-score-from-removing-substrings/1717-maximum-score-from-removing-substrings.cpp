class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int maxGain = 0;

        stack<char> myStack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'a' && s[i] != 'b') {
                stack<char> myStack2;
                while (!myStack.empty()) {
                    if (myStack2.empty()) myStack2.push(myStack.top()); 
                    else if (myStack.top() == myStack2.top()) myStack2.push(myStack.top());
                    else {
                        if (myStack.top() == 'a') maxGain += x;
                        else maxGain += y;
                        myStack2.pop();
                    }
                    myStack.pop();
                }
            }
            else if (myStack.empty()) myStack.push(s[i]);
            else if (myStack.top() == s[i]) myStack.push(s[i]);
            else if (x > y) {
                if (s[i] == 'a') myStack.push(s[i]);
                else {
                    maxGain += x;
                    myStack.pop();
                }
            }
            else if (y >= x) {
                if (s[i] == 'b') myStack.push(s[i]);
                else {
                    maxGain += y;
                    myStack.pop();
                }
            }
        }

        stack<char> myStack2;
        while (!myStack.empty()) {
            if (myStack2.empty()) myStack2.push(myStack.top()); 
            else if (myStack.top() == myStack2.top()) myStack2.push(myStack.top());
            else {
                if (myStack.top() == 'a') maxGain += x;
                else maxGain += y;
                myStack2.pop();
            }
            myStack.pop();
        }

        return maxGain;
    }
};