class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = 2 * n - 1; i >= 0; i--) {

            int ind = i % n;
            int curr = nums[ind];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) {
                if (st.empty())
                    ans[ind] = -1;
                else
                    ans[ind] = st.top();
            }

            st.push(curr);
        }

        return ans;
    }
};