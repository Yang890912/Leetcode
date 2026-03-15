class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int size = workerTimes.size();
        if (size == 1) return (long long)workerTimes[0] * (1 + mountainHeight) * mountainHeight / 2;
        
        long long l = 1;
        long long r = 1e12;

        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (f(mountainHeight, workerTimes, mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }

    bool f(long long height, vector<int>& workerTimes, long long t) {
        for (int w : workerTimes) {
            long long reduce = (long long)((sqrt(1 + 8.0 * t / w) - 1) / 2);
            height -= reduce;
            if (height <= 0) return true;
        }
        return false;
    }
};