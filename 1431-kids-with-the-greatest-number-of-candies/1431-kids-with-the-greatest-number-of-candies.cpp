class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans;
        int maxcandies = 0;
        
        for(int i = 0; i < n; i++) {
            maxcandies = max(maxcandies, candies[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxcandies) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};
