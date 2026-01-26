class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] < minDiff) {
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
                minDiff = arr[i + 1] - arr[i];
            }
            else if (arr[i + 1] - arr[i] == minDiff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};