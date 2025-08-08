class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int longestLength = 1;
        vector<pair<int, int>> prevAndLength;
        prevAndLength.push_back({0, 1});

        for (int i = 1; i < n; i++) {
            int tmpLen = 1;
            int tmpPrev = i;

            for (int j = 0; j < i; j++) {
                if (words[i].size() != words[j].size() || groups[i] == groups[j]) continue;
                
                int dis = 0;
                for (int k = 0; k < words[i].size(); k++) {
                    if (words[i][k] != words[j][k]) dis++;
                }
                if (dis != 1) continue;

                if (prevAndLength[j].second + 1 > tmpLen) {
                    tmpLen = prevAndLength[j].second + 1;
                    tmpPrev = j;
                }
            }

            prevAndLength.push_back({tmpPrev, tmpLen});

            if (longestLength < tmpLen) longestLength = tmpLen;
        }
        
        vector<string> res;
        for (int i = n - 1; i >= 0; i--) {
            if (prevAndLength[i].second == longestLength) {
                int curr = i;
                while (prevAndLength[curr].first != curr) {
                    res.push_back(words[curr]);
                    curr = prevAndLength[curr].first;
                }
                res.push_back(words[curr]);
                break;
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};