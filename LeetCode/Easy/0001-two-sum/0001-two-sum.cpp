class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int, int>> myNums;

        for (int i = 0; i < nums.size(); i++) {
            myNums.push_back(make_pair(nums[i], i));
        }
        
        sort(myNums.begin(), myNums.end());

        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            if (left == right) break;

            if (myNums[left].first + myNums[right].first == target) {
                res.push_back(myNums[left].second);
                res.push_back(myNums[right].second);
                break;
            }
            else if (myNums[left].first + myNums[right].first > target) right--;
            else left++;
        }

        return res;
    }
};