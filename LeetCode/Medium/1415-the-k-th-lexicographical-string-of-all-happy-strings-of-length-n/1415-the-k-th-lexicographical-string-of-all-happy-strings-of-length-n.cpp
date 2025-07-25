class Solution {
public:
    int numOfPath = 0;
    vector<char> letters = {'a', 'b', 'c'};
    string res = "";

    string getHappyString(int n, int k) {
        for (int i = 0; i < letters.size(); i++) {
            if (dfs(n, k, 1, letters[i])) break;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int n, int k, int level, char c) {
        if (level >= n) {
            numOfPath++;
            if (numOfPath >= k) {
                res.push_back(c);
                return true;
            }
            return false;
        }

        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] != c) {
                if (dfs(n, k, level + 1, letters[i])) {
                    res.push_back(c);
                    return true;
                }
            }
        }

        return false;
    }
};