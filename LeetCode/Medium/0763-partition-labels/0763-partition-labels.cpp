class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        vector<int> res;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        int start = 0;
        while (start < s.size()) {
            int currLast = last[s[start] - 'a'];
            for (int j = start; j <= currLast; j++) {
                if (last[s[j] - 'a'] > currLast) currLast = last[s[j] - 'a'];
            }
            res.push_back(currLast - start + 1);
            start = currLast + 1;
        }

        return res;
    }
};