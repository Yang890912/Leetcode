class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;

        for (int num : nums) {
            if (num & 1) {
                int _num = num;
                int offset = 1;
                while ((_num >>= 1) & 1) offset *= 2;
                res.push_back(num - offset);
            }
            else {
                res.push_back(-1);
            }
        }

        return res;
    }
};