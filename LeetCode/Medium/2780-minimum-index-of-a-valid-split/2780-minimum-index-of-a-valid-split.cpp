class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int cnt = 0, dominant = 0;
        for (int i = 0; i < nums.size(); i++){
            if (cnt == 0) dominant = nums[i];
            cnt += (nums[i] == dominant) ? 1 : -1;
        }

        int numOfDominant = count(nums.begin(), nums.end(), dominant);
        int currNumOfDominant = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            currNumOfDominant += (nums[i] == dominant) ? 1 : 0;
            if (currNumOfDominant > (i + 1) / 2 && 
                (numOfDominant - currNumOfDominant) > (nums.size() - i - 1) / 2) return i;
        }

        return -1;
    }
};