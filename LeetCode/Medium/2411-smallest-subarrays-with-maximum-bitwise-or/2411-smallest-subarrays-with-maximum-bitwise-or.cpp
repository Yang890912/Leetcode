class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        unordered_map<int, int> nextRightBit1;
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int pos = 0;
            while (num > 0) {
                if (num & 1) nextRightBit1[pos] = i;
                num >>= 1;
                pos++;
            }

            int currFarest = 0;
            for (auto pair : nextRightBit1) {
                // cout << i << " "<< pair.first << " " << pair.second << endl;
                currFarest = max(currFarest, pair.second);
            }

            res[i] = max(currFarest - i + 1, 1);
        }

        return res;
    }
};