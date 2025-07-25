class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> buffer;
        string num = "1";

        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'D') {
                buffer.push(num.back());
                num.pop_back();
                num.push_back(char(i + '2'));
            }
            else {
                while (!buffer.empty()) {
                    num.push_back(buffer.top());
                    buffer.pop();
                }
                num.push_back(char(i + '2'));
            }
        }

        while (!buffer.empty()) {
            num.push_back(buffer.top());
            buffer.pop();
        }

        return num;
    }
};