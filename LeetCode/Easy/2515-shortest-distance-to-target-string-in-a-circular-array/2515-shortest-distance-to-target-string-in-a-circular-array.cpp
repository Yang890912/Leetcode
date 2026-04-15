class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT_MAX;   

        for (int i = 0; i < n; i++) {
            if (words[i] != target) continue;
            res = min(res, abs(i - startIndex));
            res = min(res, n - abs(i - startIndex));
        }

        return res == INT_MAX ? -1 : res;
    }
};