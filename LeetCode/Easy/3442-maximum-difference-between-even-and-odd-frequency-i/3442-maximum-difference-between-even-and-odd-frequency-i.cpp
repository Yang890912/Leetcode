class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq('z' + 1, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        int minEven = 101, maxOdd = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 0) {
                if (freq[i] < minEven) minEven = freq[i];
            }
            else {
                if (freq[i] > maxOdd) maxOdd = freq[i];
            }
        }

        return maxOdd - minEven;
    }
};