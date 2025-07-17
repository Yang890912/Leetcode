class Solution {
public:
    int myAtoi(string s) {
        long int num = 0;
        bool isReading = false;
        bool negative = false;

        for (int i = 0; i < s.size(); i++) {
            if (!isReading && s[i] == ' ')
                continue;
            else if (!isReading && (s[i] == '-' || s[i] == '+')) {
                isReading = true;
                if (s[i] == '-')
                    negative = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                isReading = true;
                num = num * 10 + s[i] - '0';
                if (num > INT_MAX)
                    break;
            } else
                break;
        }

        if (negative && num > INT_MAX)
            num = -1 * INT_MAX - 1;
        else if (negative)
            num = -1 * num;
        else if (num > INT_MAX)
            num = INT_MAX;

        return num;
    }
};