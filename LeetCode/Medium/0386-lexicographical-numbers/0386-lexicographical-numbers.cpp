class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        string s = to_string(n);
        dfs(s, "", res);
        return res;
    }

    void dfs(string s, string prevStr, vector<int>& res) {
        for (char i = '0'; i <= '9'; i++) {
            string currStr = prevStr + i;

            if (i == '0' && prevStr.size() == 0) continue;
            if (stoi(currStr) > stoi(s)) return;

            res.push_back(stoi(currStr));

            if (currStr.size() < s.size()) dfs(s, currStr, res);
        }
    }
};