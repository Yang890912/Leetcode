class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char>> table(10);

        // construct table
        int dig = 2; 
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            table[dig].push_back(c);
            cnt++;
            if (dig != 7 && dig != 9 && cnt == 3) dig++, cnt = 0;
            else if (cnt == 4) dig++, cnt = 0;
        }

        build(res, table, digits, 0);

        return res;
    }

    void build(vector<string>& res, vector<vector<char>>& table, string& digits, int pos) {
        if (pos == digits.size()) return;

        int dig = digits[pos] - '0';
        int size = res.size();
        int lsize = table[dig].size();
        if (size == 0) {
            for (int j = 0; j < lsize; j++) {
                res.push_back(string() + table[dig][j]);
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < lsize; j++) {
                    res.push_back(res[i] + table[dig][j]);
                }
            }
        }

        res.erase(res.begin(), res.begin() + size);

        build(res, table, digits, pos + 1);

        return;
    }
};