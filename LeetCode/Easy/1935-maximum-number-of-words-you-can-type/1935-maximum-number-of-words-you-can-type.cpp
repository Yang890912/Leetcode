class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char, bool> broken;
        for (char c : brokenLetters) {
            broken[c] = true;
        }

        int res = 0;
        int cantBeTyped = false;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
                if (broken.count(text[i])) cantBeTyped = true;
            }
            else {
                if (!cantBeTyped) res++;
                cantBeTyped = false;
            }
        }
        if (!cantBeTyped) res++;

        return res;
    }
};