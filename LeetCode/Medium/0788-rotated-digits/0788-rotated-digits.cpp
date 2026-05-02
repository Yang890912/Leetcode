class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            bool flag = false;
            while (num) {
                if (num % 10 == 3 || num % 10 == 4 || num % 10 == 7) {
                    flag = false;
                    break;
                }

                if (num % 10 == 2 || num % 10 == 5 || num % 10 == 6 || num % 10 == 9)
                    flag = true;
                
                num /= 10;
            }

            if (flag) res++;
        }
        return res;
    }
};