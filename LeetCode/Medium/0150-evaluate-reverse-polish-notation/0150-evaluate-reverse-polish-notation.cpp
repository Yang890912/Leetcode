class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string s : tokens) {
            if (isInteger(s)) {
                int num = stoi(s);
                nums.push(num);
            }
            else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (s[0]== '+') nums.push(num1 + num2);
                else if (s[0] == '-') nums.push(num1 - num2);
                else if (s[0] == '*') nums.push(num1 * num2);
                else if (s[0] == '/') nums.push(num1 / num2);
            }
        }

        return nums.top();
    }

    bool isInteger(string s) {
        if (s.size() > 1) return true;
        if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') return false;
        return true;
    }
};