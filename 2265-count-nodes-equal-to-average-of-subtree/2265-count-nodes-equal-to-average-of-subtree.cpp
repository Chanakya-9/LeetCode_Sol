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
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [l_sum, l_cnt] = dfs(root->left);
        auto [r_sum, r_cnt] = dfs(root->right);

        int sum = l_sum + r_sum + root->val;
        int cnt = l_cnt + r_cnt + 1;

        if (sum / cnt == root->val) {
            ans++;
        }

        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};