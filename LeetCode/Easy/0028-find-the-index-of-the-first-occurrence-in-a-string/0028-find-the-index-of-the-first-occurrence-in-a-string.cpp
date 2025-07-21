class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (idx != -1) return idx;
            if (haystack[i] != needle[0]) continue;

            idx = i;
            for (int j = 1; j < needle.size(); j++) {
                if (i + j < haystack.size() && haystack[i + j] != needle[j]) {
                    idx = -1;
                    break;
                }
                else if (i + j >= haystack.size()) {
                    idx = -1;
                    break;
                }
            }
        }
        return idx;
    }
};