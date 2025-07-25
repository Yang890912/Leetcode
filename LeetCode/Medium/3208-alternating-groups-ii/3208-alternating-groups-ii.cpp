class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;

        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int curr = 1;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) curr = 1;
            else if (curr < k) curr++;
            
            if(curr == k) res++;
        }

        return res;
    }
};