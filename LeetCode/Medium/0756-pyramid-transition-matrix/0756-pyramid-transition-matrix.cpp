class Solution {
public:
    unordered_map<string, vector<string>> base2Top;
    unordered_map<string, bool> table;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string s : allowed) {
            base2Top[s.substr(0, 2)].push_back(s.substr(2));
            table[s.substr(0, 2)] = true;
        }

        return check("", bottom, 0, bottom.size());
    }

    bool check(string newBottom, string bottom, int pos, int n) {
        if (n == 2) {
            if (base2Top.count(bottom)) return true;
            else false;
        }

        if (pos == n - 1) {
            if (table.count(newBottom)) return table[newBottom];
            else table[newBottom] = check("", newBottom, 0, n - 1);

            return table[newBottom];
        }

        string tmp = bottom.substr(pos, 2);

        if (!base2Top.count(tmp)) return false;

        for (string s : base2Top[tmp]) {
            if(check(newBottom + s, bottom, pos + 1, n)) return true;   
        }

        return false;
    }
};