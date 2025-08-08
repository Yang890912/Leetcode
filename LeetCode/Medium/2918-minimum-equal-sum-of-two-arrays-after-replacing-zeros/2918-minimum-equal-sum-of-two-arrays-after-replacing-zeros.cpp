class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;

        int zeros1 = 0, zeros2 = 0;
        long long sum1 = 0, sum2 = 0;
        for (int num : nums1) {
            if (num == 0) sum1 +=1, zeros1++;
            else sum1 += num;
        }
        for (int num : nums2) {
            if (num == 0) sum2 += 1, zeros2++;
            else sum2 += num;
        }
        
        if (sum1 == sum2) return sum1;
        else if (sum1 > sum2 && zeros2 != 0) return sum1;
        else if (sum2 > sum1 && zeros1 != 0) return sum2;

        return -1;
    }
};