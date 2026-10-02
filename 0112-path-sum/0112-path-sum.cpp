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
int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        bool leftans = false;
        bool rightans = false;
        sum+=root->val;
        if(root->left==NULL  && root->right==NULL){
            if(sum==targetSum){
                sum-=root->val;
                return true;
            }
            // backtracking
            sum-=root->val; 
            return false;
        }
        else{
            if(root->left!=NULL){
                leftans = hasPathSum(root->left,targetSum);
            }
            if(root->right!=NULL){
                rightans = hasPathSum(root->right,targetSum);
            }
            sum-=root->val;
        }
        return leftans||rightans;
    }
};