class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1 && nums.size() >= 2) return true;

        unordered_set<int> startPts;
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && nums[j - 1] < nums[j]) {
                if ((j - i) == (k - 1)) {
                    startPts.insert(i);
                    i++;
                }
                j++;
            }
            i = j;
        }

        for (int point : startPts) {
            if (startPts.count(point + k) || 
                startPts.count(point - k)) return true;
        }

        return false;
    }
};