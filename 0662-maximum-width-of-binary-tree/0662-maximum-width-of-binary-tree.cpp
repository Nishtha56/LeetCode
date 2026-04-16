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
        int ans=0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size=q.size();
            int minId=q.front().second;
            int f, l;
            for(int i=0;i<size; i++){
                long long currId=q.front().second - minId;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0) f=currId;
                if(i==size-1) l=currId;

                if(node->left){
                    q.push({node->left, currId*2 + 1});
                }

                if(node->right){
                    q.push({node->right, currId*2 + 2});
                }
            }
            ans=max(ans, l-f+1);
        }
        return ans;
    }
};