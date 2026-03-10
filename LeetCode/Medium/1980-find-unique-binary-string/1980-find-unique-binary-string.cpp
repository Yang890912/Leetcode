class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int len = nums[0].size();
        int upper = (1 << len);
        
        string s;
        int i = 0, j = 0;
        for (; i < upper && j < n; i++, j++) {
            int num = stoi(nums[j], nullptr, 2);
            if (i == num) continue;
            s = bitset<32>(i).to_string();
            return s.substr(32 - len);
        }

        s = bitset<32>(i).to_string();
        return s.substr(32 - len);
    }
};