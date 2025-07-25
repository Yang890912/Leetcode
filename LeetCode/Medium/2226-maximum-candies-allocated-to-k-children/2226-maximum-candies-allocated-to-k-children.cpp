class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long int sum = 0;

        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }
        
        long long int left = 1;
        long long int right = sum / k;
        
        if (right == 0) return right;

        while (left <= right) {
            long long int mid = (left + right) / 2;
            long long int nums = 0;

            for (int i = 0; i < candies.size(); i++) {
                nums += candies[i] / mid;
            }

            if (nums >= k) left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};