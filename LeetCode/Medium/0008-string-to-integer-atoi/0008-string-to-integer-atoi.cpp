class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        long long sign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;

            if (s[i] == '-' || s[i] == '+') { 
                sign = (s[i] == '-') ? -1 : 1; 
                i++;
            }

            for (int j = i; j < s.size(); j++) {
                if (s[j] >= '0' && s[j] <= '9') res = res * 10 + (s[j] - '0');
                else break;

                if (sign * res >= (long long)INT_MAX) return INT_MAX;
                else if (sign * res <= (long long)INT_MIN) return INT_MIN;
            }

            break;
        }

        return sign * res;
    }
};