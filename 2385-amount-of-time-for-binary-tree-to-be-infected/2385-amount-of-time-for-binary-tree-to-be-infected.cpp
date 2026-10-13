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
void markaprents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }

    }
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_track; // node--> parent
        markaprents(root,parent_track);
          TreeNode* startnode = root;
          queue<TreeNode*>q;
          q.push(root);
          while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start){
                startnode = node;
            }     
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
            unordered_map<TreeNode* , bool> visited;
               queue<TreeNode*>Q;
               Q.push(startnode);
               visited[startnode] = true;
               int minutes = 0;
               while(!Q.empty()){
                int size = Q.size();
                //check karo ki is level se aage infection spread hogi ya nahi
                bool spread = false;
                for(int i=0; i<size; i++){
                    TreeNode* current = Q.front();
                    Q.pop();
                    if(current->left && !visited[current->left]){
                    Q.push(current->left);
                    visited[current->left] = true;
                    spread = true;
                }
                 if(current->right && !visited[current->right]){
                    Q.push(current->right);
                    visited[current->right] = true;
                    spread = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    Q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                    spread = true;
                }
                }
                if(spread == true) minutes++;
               }
               return minutes;
          }
};