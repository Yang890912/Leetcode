class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        vector<int> count(1001, 0);

        for (int i = 0; i < answers.size(); i++) {
            count[answers[i]]++;
            if (count[answers[i]] == answers[i] + 1) {
                res += count[answers[i]];
                count[answers[i]] = 0;
            }
        }

        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) res += i + 1;    
        }

        return res;
    }
};