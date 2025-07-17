class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> us;
        
        while (right < s.size()) {
            if (us.find(s[right]) == us.end()) us.insert(s[right++]);
            else {
                longest = max(longest, right - left);
                while (left < right) {
                    us.erase(s[left]);
                    if (s[left++] == s[right]) break;
                }
            }
        }

        return max(longest, right - left);
    }
};