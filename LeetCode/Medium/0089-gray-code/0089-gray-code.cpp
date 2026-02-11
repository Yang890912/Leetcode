class Solution {
public:
    vector<int> grayCode(int n) {
        int m = 1 << n;
        vector<int> code(m);

        for (int i = 0; i < m; i++) {
            code[i] = i ^ (i >> 1);
        }

        return code;
    }
};