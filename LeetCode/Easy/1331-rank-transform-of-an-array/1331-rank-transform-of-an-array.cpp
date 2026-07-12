class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i); 

        int rank = 1;
        int prev = INT_MAX;
        for (auto& key : mp) {
            for (int& val : key.second)
                res[val] = rank;
            rank++;
        }

        return res;
    }
};