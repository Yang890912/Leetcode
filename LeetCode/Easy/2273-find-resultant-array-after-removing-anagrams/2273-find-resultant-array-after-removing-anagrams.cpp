class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;

        int i = 0;
        res.push_back(words[i]);
        sort(words[i].begin(), words[i].end());
        for (int j = 1; j < words.size(); j++) {
            string s = words[j];
            sort(words[j].begin(), words[j].end());
            
            if (words[i] == words[j]) continue;
            else {
                i = j;
                res.push_back(s);
            }
        }

        return res;
    }
};