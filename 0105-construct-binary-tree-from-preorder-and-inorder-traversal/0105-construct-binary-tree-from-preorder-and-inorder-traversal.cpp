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
 TreeNode* BUILDTREE(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp,int preStart,int preEnd,
 int inStart, int inEnd){
    if(preStart > preEnd || inStart > inEnd) return NULL;
     TreeNode* root = new TreeNode(preorder[preStart]);

    int inorderRoot = mp[root->val];
    int numsleft = inorderRoot - inStart;

    root->left = BUILDTREE(preorder,inorder,mp,preStart+1,preStart+numsleft,inStart,inorderRoot-1);
    root->right = BUILDTREE(preorder,inorder,mp,preStart+numsleft+1,preEnd,inorderRoot+1,inEnd);
    return root;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = BUILDTREE(preorder,inorder,mp,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};