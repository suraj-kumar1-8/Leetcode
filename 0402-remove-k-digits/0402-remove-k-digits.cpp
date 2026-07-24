class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char ch : num) {
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};