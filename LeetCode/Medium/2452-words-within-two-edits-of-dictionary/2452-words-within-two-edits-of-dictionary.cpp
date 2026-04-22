class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (string& s1 : queries) {
            for (string& s2 : dictionary) {
                int diff = 0;
                for (int i = 0; i < s1.size(); i++) {
                    if (s1[i] != s2[i]) diff++;
                    if (diff > 2) break; 
                }

                if (diff <= 2) {
                    res.push_back(s1);
                    break;
                }
            }
        }

        return res;
    }
};