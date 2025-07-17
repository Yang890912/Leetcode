class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> myNums;
        for (int n : nums) {
            myNums.push(n);
        }   

        int numOfIter = 0;
        while (true) {
            if (myNums.top() >= k) break;
            long long int x = myNums.top();
            myNums.pop();
            long long int y = myNums.top();
            myNums.pop();
            
            myNums.push(min(x, y) * 2 + max(x, y));

            numOfIter++;
        }
        return numOfIter;
    }
};