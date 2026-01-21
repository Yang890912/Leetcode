class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();
        int sum = 0;
        for (int& a : apple) sum += a;

        sort(capacity.begin(), capacity.end());

        for (int i = n - 1; i >= 0; i--) {
            sum -= capacity[i];
            if (sum <= 0) return n - i;
        }

        return -1;
    }
};