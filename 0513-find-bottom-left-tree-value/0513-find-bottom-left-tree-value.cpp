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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int left=0;
        while(!q.empty()){
            int s=q.size();
            vector<int> l;
            for(int i=0;i<s;i++){
                TreeNode* a=q.front();
                q.pop();
                if(i==0){
                    left=a->val;
                }

                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
        }

        return left;
    }
};