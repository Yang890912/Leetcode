class Solution {
public:
    string answerString(string word, int numFriends) {
        int maxLen = word.size() - numFriends + 1;
        string res = "";

        if (numFriends == 1) return word;

        for (int i = 0; i < word.size(); i++) {
            string subStr;
            if (i + maxLen > word.size()) subStr = word.substr(i);
            else subStr = word.substr(i, maxLen);

            if (subStr > res) res = subStr;
        }

        return res;
    }
};