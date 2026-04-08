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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            bool fx= false, fy=false;
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();

                //we got the x and y
                if(curr->val == x) fx=true;
                if(curr->val == y) fy=true;

                //same parent
                if(curr->left && curr->right){
                    if((curr->left->val==x && curr->right->val==y) || (curr->left->val==y && curr->right->val==x)){
                        return false;
                    }
                }
                

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            if(fx && fy) return true;
            if(fx || fy) return false; //one found one not found
        }
        return false;
    }
};