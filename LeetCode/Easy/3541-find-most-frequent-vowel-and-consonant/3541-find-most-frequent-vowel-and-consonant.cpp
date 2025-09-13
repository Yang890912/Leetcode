class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> um;
        int maxVowel = 0, maxConsonant = 0;
        for (char c : s) {
            um[c]++;
            if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') && um[c] > maxVowel)
                maxVowel = um[c];
            else if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && um[c] > maxConsonant) 
                maxConsonant = um[c];
        }

        return maxVowel + maxConsonant;
    }
};