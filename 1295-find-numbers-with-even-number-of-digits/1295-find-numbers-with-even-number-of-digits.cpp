class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(nums[i]>0){

            
            
            cnt++;
            nums[i]=nums[i]/10;
            }
            if(cnt%2==0){
                ans++;
            }


        }
        return ans;
    }
};