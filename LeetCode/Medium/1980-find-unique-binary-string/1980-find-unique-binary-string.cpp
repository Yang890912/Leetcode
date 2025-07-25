class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int onesMask = (1 << nums.size()) - 1;
        int count = 0;

        while (left <= right) {
            int lNum = stoi(nums[left], nullptr, 2);
            int rNum = stoi(nums[right], nullptr, 2);

            if (rNum != onesMask - count) {
                bitset<16> binary(onesMask - count);
                return binary.to_string().substr(16 - nums.size());
            }
            else if (lNum != count) {
                bitset<16> binary(count);
                return binary.to_string().substr(16 - nums.size());
            }

            left++;
            right--;
            count++;
        }
        
        bitset<16> binary(onesMask - count);
        return binary.to_string().substr(16 - nums.size());
    }
};