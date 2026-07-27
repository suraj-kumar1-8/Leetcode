class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int left=0;
        int right=nums.size()-1;
        while(left<nums.size() && nums[left]==temp[left]){
            left++;
        }
        while(right>left && nums[right]==temp[right]){
            right--;

        }
        if(left==nums.size()){
            return 0;
        }
        return (right-left+1);
    }
};