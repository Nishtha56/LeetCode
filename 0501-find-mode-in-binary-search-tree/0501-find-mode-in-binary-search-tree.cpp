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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            int a=curr->val;
            mp[a]++;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        } 
        int maxi=0;
        for(auto &it : mp){
            int a=it.second;
            maxi=max(maxi, a);
        }
        for(auto &it : mp){
            if(maxi==it.second){
                res.push_back(it.first);
            }
        }
        return res;
    }
};