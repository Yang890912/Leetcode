class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] <= '9' && word[i] >= '0') continue;
            else if (word[i] <= 'Z' && word[i] >= 'A') {
                if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') 
                    hasVowel = true;
                else hasConsonant = true;
            }
            else if (word[i] <= 'z' && word[i] >= 'a') {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') 
                    hasVowel = true;
                else hasConsonant = true;      
            }
            else return false;
        }
        
        return hasVowel && hasConsonant;
    }
};