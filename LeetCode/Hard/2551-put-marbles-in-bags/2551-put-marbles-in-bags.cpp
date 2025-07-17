class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> cut;
        
        for (int i = 0; i < weights.size() - 1; i++) {
            cut.push_back(weights[i] + weights[i + 1]);
        }

        sort(cut.begin(), cut.end());

        long long maximum = accumulate(cut.rbegin(), cut.rbegin() + (k - 1), 0LL);
        long long minimum = accumulate(cut.begin(), cut.begin() + (k - 1), 0LL);
    
        return maximum - minimum;

    }
};