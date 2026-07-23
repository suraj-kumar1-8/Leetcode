class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int curr = prices[i];

            while (!st.empty() && st.top() > curr) {
                st.pop();
            }

            if (!st.empty()) {
                prices[i] = curr - st.top();
            }

            st.push(curr);
        }

        return prices;
    }
};