class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();

        for (int i = 0; i < n; i++) {
            string c = operations[i];

            if (c != "+" && c != "D" && c != "C") {
                st.push(stoi(c));
            }
            else if (c == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }
            else if (c == "D") {
                st.push(2 * st.top());
            }
            else {   
                st.pop();
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};