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
int maxpath = 0;
int path(TreeNode* root){
    if(root==NULL) return 0;
    int left = path(root->left);
    int right = path(root->right);
    int leftpath = 0;
    if(root->left!=NULL){
        if(root->left->val == root->val){
            leftpath = left+1;
        }
    }

     int rightpath = 0;
    if(root->right!=NULL){
        if(root->right->val == root->val){
            rightpath = right+1;
        }
    }
    maxpath = max(maxpath,leftpath+rightpath);
    return max(leftpath,rightpath);
}
    int longestUnivaluePath(TreeNode* root) {
        path(root);
        return maxpath;
    }
};