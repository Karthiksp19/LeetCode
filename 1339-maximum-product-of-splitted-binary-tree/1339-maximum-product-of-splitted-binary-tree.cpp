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
    long long sum(TreeNode* root){
        if(root == nullptr) return 0;

        long long left = sum(root->left);
        long long right = sum(root->right);
        return left + right + root->val;
    }

    long long subtree(TreeNode* root,long long totalsum, long long &sum){
        if(root == nullptr) return 0;

        long long left = subtree(root->left, totalsum, sum);
        long long right = subtree(root->right, totalsum, sum);
        long long currsum = left + right + root->val;
        sum = max(sum, currsum * (totalsum - currsum));
        return currsum ;
    }

    int maxProduct(TreeNode* root) {
        if(root == nullptr) return 0;

        long long totals = sum(root);
        long long max_sum = 0;
        long long totals2 = subtree(root, totals, max_sum);
        return max_sum % (long long)(1e9 + 7);
    }
};