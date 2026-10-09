/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool pPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path1) {
    if (root == NULL) return false;
    path1.push_back(root);
    if (root == p) return true;

    if (pPath(root->left, p, path1) || pPath(root->right, p, path1))
        return true;

    path1.pop_back();
    return false;
}

bool qPath(TreeNode* root, TreeNode* q, vector<TreeNode*>& path2) {
    if (root == NULL) return false;
    path2.push_back(root);
    if (root == q) return true;

    if (qPath(root->left, q, path2) || qPath(root->right, q, path2))
        return true;

    path2.pop_back();
    return false;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*> path1;
        vector<TreeNode*> path2;
      pPath(root,p,path1);
      qPath(root,q,path2);
      int i = 0;
   while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
    i++;
   }

   return path1[i-1];
    }
};