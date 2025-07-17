class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> us;

        if (nums.size() < 4) return res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 3; j < nums.size(); j++) {
                int left = i + 1;
                int right = j - 1;
                long long newTarget = (long long) target - nums[i] - nums[j];

                while (left < right) {
                    if (nums[left] + nums[right] > newTarget) right--;
                    else if (nums[left] + nums[right] < newTarget) left++;
                    else {
                        us.insert({nums[i], nums[left], nums[right], nums[j]});
                        left++;
                        right--;
                    }
                }
            }
        }

        for (const auto& vec : us) {
            res.push_back(vec);
        }
        return res;
    }
};