class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1e14;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long numOfRepair = 0;

            for (int i = 0; i < ranks.size(); i++) {
                numOfRepair += sqrt(mid / ranks[i]);
                if (numOfRepair >= cars) break;
            }

            if (numOfRepair >= cars) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }

};