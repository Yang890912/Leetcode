class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int res = 0;
        int cnt = 0;

        for (int i = 0; i < cost.size(); i++) {
            cnt++;
            if (cnt != 3) res += cost[i];
            else cnt = 0;
        }

        return res;
    }
};