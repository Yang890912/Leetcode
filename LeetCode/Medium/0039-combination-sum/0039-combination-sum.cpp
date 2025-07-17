class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        map<int, vector<vector<int>>> res;
 
        for (int t = 1; t <= target; t++) {
            res[t] = {};
        }

        for (int i = 0; i < candidates.size(); i++) {
            res[candidates[i]].push_back({candidates[i]});
        }

        for (int t = 1; t <= target; t++) {
            for (int i = 0; i < candidates.size(); i++) {
                if (candidates[i] >= t) continue;
                for (vector<int> r : res[t - candidates[i]]) {
                    if (r.back() <= candidates[i]) {
                        vector<int> add = {candidates[i]};
                        vector<int> combin(r);
                        combin.insert(combin.end(), add.begin(), add.end());
                        res[t].push_back(combin);
                    }
                }
            }
        }

        return res[target];
    }
};