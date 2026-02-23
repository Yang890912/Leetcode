class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.size();
        const int expected = pow(2, k);
        if (n < k) return false;

        unordered_set<string> codes;
        for (int i = 0; i <= n - k; i++) {
            codes.insert(s.substr(i, k));
        }

        return codes.size() == expected;
    }
};