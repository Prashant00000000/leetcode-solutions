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
    int widthOfBinaryTree(TreeNode* root) {
         if(root==NULL) return 0;
      queue<pair<TreeNode*, long long>> q;
        long long ans = 0;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second; // to make the index starting from zero
            long long first = 0, last = 0;
            for(int i=0; i<size; i++){
                long long currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = currIndex;
                if(i==size-1) last = currIndex;
                if(node->left) q.push({node->left,currIndex*2+1});
                if(node->right) q.push({node->right,currIndex*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};