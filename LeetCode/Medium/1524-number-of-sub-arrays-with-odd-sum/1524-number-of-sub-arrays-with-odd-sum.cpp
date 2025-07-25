class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int numOfOdd = 0;
        int numOfEven = 1;
        int prefixSum = 0;
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum % 2 == 0) {
                res = (res + numOfOdd) % 1000000007;
                numOfEven++;
            }
            else {
                res = (res + numOfEven) % 1000000007;
                numOfOdd++;
            }
        }
        
        return res;
    }
};