class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        set<int> needTeach;

        for (const auto& p : friendships) {
            bool canCom = false;
            int x = p[0] - 1;
            int y = p[1] - 1;
            for (const int& l1 : languages[x]) {
                for (const int& l2 : languages[y]) {
                    if (l1 == l2) {canCom = true; break;}
                }
                if (canCom) break;
            }

            if (!canCom) {
                needTeach.insert(x);
                needTeach.insert(y);
            }
        }

        int res = needTeach.size();
        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (const auto& x : needTeach) {
                bool found = false;
                for (const int& l : languages[x]) {
                    if (l == i) {found = true; break;}
                }
                if (!found) count++;
            }
            res = min(res, count);
        }

        return res;
    }
};