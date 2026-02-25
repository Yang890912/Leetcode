class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int currMin = INT_MAX;
            int idx = i;
            for (int j = i; j < n; j++) {
                int num = arr[j];
                int count = 0;
                while (num) {
                    if (num & 1) count++;
                    num >>= 1;
                }

                if (count < currMin) {
                    idx = j;
                    currMin = count;
                }
                else if (count == currMin && arr[j] < arr[idx]) {
                    idx = j;
                }
            }
            swap(arr[i], arr[idx]);
        }

        return arr;
    }
};