class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;

        int i = 0;
        while (i < word.size()) {
            int j = i + 1;
            while (j < word.size() && word[j] == word[i]) {
                res++;
                j++;
            }
            i = j;
        }

        return res;
    }
};