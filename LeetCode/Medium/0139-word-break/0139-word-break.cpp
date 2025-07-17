class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> fromDict(s.size(), vector<int>(s.size(), 0));
        unordered_set<string> wordDictUs(wordDict.begin(), wordDict.end());

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (wordDictUs.count(s.substr(i, j - i + 1)) == 1) fromDict[i][j] = 1;
            }
        }

        return recursive(0, s.size() - 1, fromDict);
    }

    bool recursive(int left, int right, vector<vector<int>>& fromDict) {
        if (fromDict[left][right] == 1) return true;
        else if (fromDict[left][right] == -1) return false;

        for (int i = left; i < right; i++) {
            if (recursive(left, i, fromDict) && recursive(i + 1, right, fromDict)) {
                fromDict[left][right] = 1;
                return true;
            }
        }
        
        fromDict[left][right] = -1;
        return false;
    }
};