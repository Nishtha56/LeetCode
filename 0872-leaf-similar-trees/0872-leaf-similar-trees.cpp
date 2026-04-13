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
    void dfs(vector<int>& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
        }
        dfs(ans, root->left);
        dfs(ans, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;

        dfs(ans1, root1);
        dfs(ans2, root2);
        if(ans1.size()!=ans2.size()){
            return false;
        }
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i]){
                return false;
            }
        }
        return true;
    }
};