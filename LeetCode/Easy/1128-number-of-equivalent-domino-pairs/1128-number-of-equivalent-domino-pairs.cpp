class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> um;
        for (auto domino : dominoes) {
            int smaller = min(domino[0], domino[1]);
            int larger = max(domino[0], domino[1]);
            um[{smaller, larger}]++;
        }

        int res = 0;
        for (auto element : um) {
            res += element.second * (element.second - 1) / 2;
        }

        return res;
    }
};