/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
    int dfs(TreeNode* root, int max_val){
        if(root==nullptr){
            return 0;
        }
        max_val=max(root->val,max_val);
        int left=dfs(root->left,max_val);
        int right=dfs(root->right,max_val);
        int cnt=0;
        if(root->val>=max_val){
            cnt++;
        }
        return left+right+cnt;
    }
};