class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> inp('z' + 1, 0);
        for (char c : p) inp[c]++;

        int left = 0, right = 0;
        while (left < s.size() && right < s.size()) {
            if (inp[s[right]] == 0) {
                inp[s[left]]++;
                left++;
                if (left == right) right = left;
                continue;
            }

            inp[s[right]]--;
            if (right - left == p.size() - 1) {
                res.push_back(left);
                inp[s[left]]++;
                left++;
            }
            right++;
        }

        return res;
    }
};