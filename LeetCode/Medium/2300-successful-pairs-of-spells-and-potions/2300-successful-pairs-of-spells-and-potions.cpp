class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> res;
        for (int spell : spells) {
            long long target = success / spell;
            if (success % spell) target += 1;

            int left = 0;
            int right = m - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (potions[mid] < target) left = mid + 1;
                else right = mid - 1;
            }

            res.push_back(m - left);
        }

        return res;
    }
};