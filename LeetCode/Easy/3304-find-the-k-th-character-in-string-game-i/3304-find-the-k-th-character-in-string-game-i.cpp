class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while (word.size() < k) {
            int n = word.size();
            for (int i = 0; i < n; i++) {
                char nextChar = 'a' + ((word[i] + 1 - 'a') % 26);
                word += nextChar;
            }
        }
        
        return word[k - 1];
    }
};