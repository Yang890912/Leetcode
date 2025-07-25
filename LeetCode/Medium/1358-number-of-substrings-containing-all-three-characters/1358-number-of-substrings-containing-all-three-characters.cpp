class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int left = 0;
        vector<int> nums(3, 0);

        for (int right = 0; right < s.size(); right++) {
            nums[s[right] - 'a']++;
            while (nums[0] >= 1 && nums[1] >= 1 && nums[2] >= 1) {
                res += s.size() - right;
                nums[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};