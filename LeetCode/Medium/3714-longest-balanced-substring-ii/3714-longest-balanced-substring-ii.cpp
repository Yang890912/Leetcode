class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        if (n == 1) return 1;

        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) count++;
            else count = 1;
            res = max(res, count);
        }

        res = max(res, findMaxWith2('a', 'b', 'c', s));
        res = max(res, findMaxWith2('b', 'c', 'a', s));
        res = max(res, findMaxWith2('a', 'c', 'b', s));

        map<pair<int, int>, int> pair2Pos;
        pair2Pos[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i]  == 'b') b++;
            else c++;

            if (pair2Pos.count({b - a, c - a})) res = max(res, i - pair2Pos[{b - a, c - a}]);
            else pair2Pos[{b - a, c - a}] = i;
        }

        return res;
    }

    int findMaxWith2(char tar1, char tar2, char ignore, string& s) {
        int n = s.size();
        int i = 0;
        int maxL = 0;

        while (i < n) {
            if (s[i] == ignore) {
                i++;
                continue;
            }

            unordered_map<int, int> freq;
            freq[tar1] = 0;
            freq[tar2] = 0;
            int j = i;
            while (j < n && s[j] != ignore) {
                freq[s[j]]++;
                maxL = max(maxL, min(freq[tar1], freq[tar2]) * 2);
                j++;
            }

            i = j;
        }

        return maxL;
    }
};