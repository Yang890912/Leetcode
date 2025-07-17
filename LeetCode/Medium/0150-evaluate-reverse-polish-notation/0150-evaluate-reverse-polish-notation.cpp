class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(left + right);
            }
            else if (tokens[i] == "-") {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(left - right);
            }
            else if (tokens[i] == "*") {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(left * right);
            }
            else if (tokens[i] == "/") {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(left / right);
            }
            else {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};