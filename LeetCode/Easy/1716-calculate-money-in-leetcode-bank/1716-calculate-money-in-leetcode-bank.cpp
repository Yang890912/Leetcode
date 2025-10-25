class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int i = 1;
        int weekSum = 28;

        while (n >= 7) {
            total += weekSum;
            weekSum += 7;
            n -= 7;
            i++;
        }

        while (n >= 1) {
            total += i;
            n--;
            i++;
        }

        return total;
    }
};