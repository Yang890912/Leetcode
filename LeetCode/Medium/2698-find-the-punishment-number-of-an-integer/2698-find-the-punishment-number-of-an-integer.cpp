class Solution {
public:
    bool check(string& testNum, int target, int idx=0, int sum=0) {
        if (testNum.size() == idx) return sum == target;
        int num = 0;
        for (int i = idx; i < testNum.size(); i++) {
            num = num * 10 + (testNum[i] - '0');
            if (sum + num > target) break;
            if (check(testNum, target, i + 1, sum + num)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string squareNum = to_string(i * i);
            if (check(squareNum, i)) res += i * i;
        }
        return res;
    }
};