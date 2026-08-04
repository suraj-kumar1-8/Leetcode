class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int j = 0;
        for (int i = nums[0]; i <= nums.back(); i++) {
            if (j < nums.size() && nums[j] == i)
                j++;
            else
                ans.push_back(i);
        }

        return ans;
    }
};