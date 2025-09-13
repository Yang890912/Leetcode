class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> um;
        
        for (char c : s) um[c]++;

        int maxVowel = 0, maxConsonant = 0;
        for (const auto& [key, val] : um) {
            if ((key == 'a' || key == 'e' || key == 'i' || key == 'o' || key == 'u') && um[key] > maxVowel)
                maxVowel = um[key];
            else if (key != 'a' && key != 'e' && key != 'i' && key != 'o' && key != 'u' && um[key] > maxConsonant) 
                maxConsonant = um[key];
        }

        return maxVowel + maxConsonant;
    }
};