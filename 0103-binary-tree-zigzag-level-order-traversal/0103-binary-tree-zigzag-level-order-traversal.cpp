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
        vector<vector<int>>ans;
        vector<int>temp;
        queue<TreeNode*>q;

        if(root==NULL) return {};

        int level = 0;
        q.push(root);
        level++;

        while(!q.empty()){
            int size = q.size();

            temp.resize(size);   // current level ke liye size fix

            for(int i=0; i<size; i++){
                TreeNode* ele = q.front();

                if(level%2!=0){
                    temp[i] = ele->val;              
                }
                else{
                    temp[size-i-1] = ele->val;   
                }

                if(ele->left!=NULL){
                    q.push(ele->left);
                }

                if(ele->right!=NULL){
                    q.push(ele->right);
                }

                q.pop();
            }

            ans.push_back(temp);
            temp.clear();
            level++;
        }

        return ans;
    }
};