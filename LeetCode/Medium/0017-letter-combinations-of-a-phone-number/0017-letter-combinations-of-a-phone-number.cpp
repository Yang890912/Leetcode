class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;

        vector<vector<char>> map('9' + 1);
        char curr = '2';
        int i = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            map[curr].push_back(c);
            i++;
            if (i == 4 && (curr == '7' || curr == '9')) curr++, i = 0;
            if (i == 3 && (curr != '7' && curr != '9')) curr++, i = 0;
        }

        construct(res, map, digits, 0);

        return res;
    }

    void construct(vector<string>& res, 
                    const vector<vector<char>> map, 
                    const string digits, 
                    int idx) {
                        
        if (idx == digits.size() - 1) {
            for (char c : map[digits[idx]]) {
                string ss = "";
                ss += c;
                res.push_back(ss);
            }
            return;
        }

        construct(res, map, digits, idx + 1);
        vector<string> tmp;
        for (char c : map[digits[idx]]) {
            for (string s : res) {
                string ss = "";
                ss += c + s;
                tmp.push_back(ss);
            }
        }
        res = tmp;

        return;
    }
};