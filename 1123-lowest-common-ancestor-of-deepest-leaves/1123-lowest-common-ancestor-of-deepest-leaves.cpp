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
int height(TreeNode* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left,right);
}
TreeNode* solve(TreeNode* root){
    if(root==NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    if(left == right) return root;
    if(left > right) return solve(root->left);
    else return  solve(root->right);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root== NULL) return NULL;
       return solve(root);
    }
};