class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> freq(4, 0);
        int x = 0;
        int y = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') y++, freq[0]++;
            else if (s[i] == 'S') y--, freq[1]++;
            else if (s[i] == 'E') x++, freq[2]++;
            else if (s[i] == 'W') x--, freq[3]++;

            res = max(
                res, 
                abs(x) + abs(y) + min(min(freq[0], freq[1]) + min(freq[2], freq[3]), k) * 2
            );
        }

        return res;
    }
};