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
int maxsum = INT_MIN;
int sum(TreeNode* root){
    if(root==NULL) return 0;
    int ls = sum(root->left);
    int rs = sum(root->right);
    if(ls<0){
        ls = 0;
    }
    if(rs<0) {
        rs = 0;
    }
    maxsum = max(maxsum,ls+rs+root->val);
    return root->val + max(ls,rs);
}
    int maxPathSum(TreeNode* root) {
     sum(root);
        return maxsum;
    }
};