class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> visited(26, false);
        string ans = "";

        for (char ch : s) {

            freq[ch - 'a']--;

            if (visited[ch - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > ch &&
                   freq[ans.back() - 'a'] > 0) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }
};