class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        stack<char> st1;
        stack<char> st2;

        for(int i = 0; i < n; i++) {
            if(s[i] != '#') {
                st1.push(s[i]);
            }
            else {
                if(!st1.empty())
                    st1.pop();
            }
        }

        for(int i = 0; i < m; i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            }
            else {
                if(!st2.empty())
                    st2.pop();
            }
        }

        return st1 == st2;
    }
};