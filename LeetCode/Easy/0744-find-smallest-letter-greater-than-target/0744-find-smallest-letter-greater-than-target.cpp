class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        if (letters[n - 1] <= target) return letters[0];
        
        char res;
        for (char c : letters) {
            if (c > target) {
                res = c;
                break;
            }
        }

        return res;
    }
};