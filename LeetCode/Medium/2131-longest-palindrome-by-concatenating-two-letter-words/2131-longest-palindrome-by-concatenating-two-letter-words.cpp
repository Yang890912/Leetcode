class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string, int> um;
        
        for (const string word : words) {
            string w = "";
            w += word[1];
            w += word[0];

            if (um.count(w) && um[w] > 0) {
                res += 4;
                um[w]--;
            }
            else {
                um[word]++;
            }
        }

        for (const auto& pair : um) {
            if (pair.first[0] == pair.first[1] && pair.second > 0) {
                res += 2;
                break;
            }
        }

        return res;
    }
};