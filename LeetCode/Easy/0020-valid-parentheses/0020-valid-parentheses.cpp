class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        map<char, char> myMap = {{')', '('}, {']', '['}, {'}', '{'}};
        for (int i = 0; i < s.size(); i++) {
            if (myStack.empty() || myStack.top() != myMap[s[i]])
                myStack.push(s[i]);
            else
                myStack.pop();
        }
        return (myStack.empty()) ? true : false;
    }
};