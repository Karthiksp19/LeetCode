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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LtR = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                int idx = LtR ? i : size - i - 1;
                TreeNode* curr = q.front();
                q.pop();
                level[idx] = curr->val;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            LtR = !LtR;
            ans.push_back(level);
        }
        return ans;
    }
};