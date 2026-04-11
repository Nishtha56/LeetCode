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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> l;
            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                l.push_back(a->val);
                
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);

            }
            int maxi=*max_element(l.begin(), l.end());
            ans.push_back(maxi);
        }
        return ans;
    }
};