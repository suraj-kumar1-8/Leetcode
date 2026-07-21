class Solution {
private:
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubArrayMins(vector<int>& nums) {
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

    long long sumSubArrayMaxs(vector<int>& nums) {
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubArrayMaxs(nums) - sumSubArrayMins(nums);
    }
};