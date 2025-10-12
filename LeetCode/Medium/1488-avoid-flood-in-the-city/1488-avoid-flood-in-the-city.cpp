class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), -1);

        unordered_map<int, int> full;
        set<int> canDry;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                canDry.insert(i);
                continue;
            }

            if (full.count(rains[i])) {
                auto it = canDry.lower_bound(full[rains[i]]);
                if (*it > full[rains[i]] && *it < i) res[*it] = rains[i];
                else return {};

                canDry.erase(*it);
            }

            full[rains[i]] = i;
        }

        for (int dry : canDry) res[dry] = 1;

        return res;
    }
};