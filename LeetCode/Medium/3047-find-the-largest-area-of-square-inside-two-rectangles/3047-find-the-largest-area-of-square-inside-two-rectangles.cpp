class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                int a1 = bottomLeft[i][0], b1 = bottomLeft[i][1];
                int c1 = topRight[i][0], d1 = topRight[i][1];
                int a2 = bottomLeft[j][0], b2 = bottomLeft[j][1];
                int c2 = topRight[j][0], d2 = topRight[j][1];

                if (a2 >= c1 || b2 >= d1 || a1 >= c2 || b1 >= d2) continue;
                
                vector<int> x = {a1, c1, a2, c2};
                vector<int> y = {b1, d1, b2, d2};
                sort(x.begin(), x.end());
                sort(y.begin(), y.end());

                long long l = x[2] - x[1];
                long long w = y[2] - y[1];
                res = max(res, min(w, l) * min(w, l));
            }
        }

        return res;
    }
};