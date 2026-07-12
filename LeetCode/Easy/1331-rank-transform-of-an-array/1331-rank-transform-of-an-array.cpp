class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> st = arr;
        sort(st.begin(), st.end());
        
        unordered_map<int, int> um;
        int rank = 1;
        for (int i = 0; i < n; i++) {
            if (um.find(st[i]) == um.end()) {
                um[st[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = um[arr[i]];
        }

        return arr;
    }
};