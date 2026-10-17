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
    TreeNode* BUILDTREE(vector<int>& postorder, vector<int>& inorder,
    unordered_map<int,int>& mp, int postStart, int postEnd,
    int inStart, int inEnd) {

        if(postStart < postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postStart]);

        int inorderRoot = mp[root->val];
        int numsleft = inorderRoot - inStart;
        int numsright = inEnd - inorderRoot; // CHANGE: right subtree ka size

        // CHANGE: right subtree mein numsright nodes hain
        root->right = BUILDTREE(postorder, inorder, mp,
            postStart - 1, postStart - numsright,
            inorderRoot + 1, inEnd);

        root->left = BUILDTREE(postorder, inorder, mp,
            postStart - numsright - 1, postEnd,
            inStart, inorderRoot - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = BUILDTREE(postorder, inorder, mp,
            postorder.size() - 1, 0, 0, inorder.size() - 1);

        return root;
    }
};