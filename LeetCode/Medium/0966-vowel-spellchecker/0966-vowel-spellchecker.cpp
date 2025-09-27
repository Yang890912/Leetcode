class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> myList;
        unordered_map<string, pair<string, int>> firstInWordlist;

        for (int i = 0; i < wordlist.size(); i++) {
            string s = wordlist[i];
            string sl = toLower(s);
            myList.insert(s);
            if (!firstInWordlist.count(sl)) {
                firstInWordlist[sl] = {s, i};
            }
        }

        vector<string> res;
        for (string s : queries) {
            string sl = toLower(s);
            if (myList.count(s)) {
                res.push_back(s);
            }
            else if (firstInWordlist.count(sl)) {
                res.push_back(firstInWordlist[sl].first);
            }
            else {
                string match = "";
                int currMin = wordlist.size();
                vowelErrChecker(0, sl, currMin, match, firstInWordlist);
                res.push_back(match);
            }
        }

        return res;
    }

    void vowelErrChecker(int pos, string s, int& currMin, string& match, 
                         unordered_map<string, pair<string, int>>& firstInWordlist) {

        if (pos >= s.size()) return;

        if (s[pos] != 'a' && s[pos] != 'e' && 
            s[pos] != 'i' && s[pos] != 'o' && s[pos] != 'u') {
            vowelErrChecker(pos + 1, s, currMin, match, firstInWordlist);
        }
        else {
            vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
            for (char vowel : vowels) {
                s[pos] = vowel;
                if (firstInWordlist.count(s) && firstInWordlist[s].second < currMin) {
                    currMin = firstInWordlist[s].second;
                    match = firstInWordlist[s].first;
                }
                vowelErrChecker(pos + 1, s, currMin, match, firstInWordlist);
            }
        }

        return;
    }

    string toLower(const string& s) {
        string res = s;
        transform(res.begin(), res.end(), res.begin(),
                    [](unsigned char c){ return tolower(c); });

        return res;
    }
};