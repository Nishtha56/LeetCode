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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int size=q.size();
            int prev;
            if(prev%2==0){    //first elemwnt compare
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }

            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                
                int val=a->val;

                //Even level
            // Strinctly increasing and odd
                if(level%2==0){
                    if(val % 2 ==0 || prev >= val){
                        return false;
                    }
                }

                //odd level
                //Strictly dec and even
                else{
                    if(val%2 !=0 ||prev <= val){
                        return false;
                    }
                }
                prev=val;

                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);

            }
            level++;
        }
        return true;
    

    }
};