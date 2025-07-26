class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = -1;

        vector<int> freq(501, 0);
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        for (int i = 1; i < 501; i++) {
            if (i == freq[i] && i > res) res = i;
        }

        return res;
    }
};