class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfs(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        if (!dfs(root->left, low, root->val))
            return false;

        if (!dfs(root->right, root->val, high))
            return false;

        return true;
    }
};