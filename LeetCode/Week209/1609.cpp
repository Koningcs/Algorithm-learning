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
    int x[100005];
    bool flag = 1;
    void dfs(TreeNode* root, int deep) {
        if(flag == 0) return;
        if(root == nullptr) return;
        //printf("%d %d %d %d\n",root->val, deep, flag,x[deep]);
        if(deep%2 == 0) {
            if(root->val % 2 == 0) {
                flag = 0; return;
            }
            if(x[deep] >= root->val) {
                flag = 0;return;
            }
            x[deep] = root->val;
        }
        else {
            if(root->val % 2 != 0) {
                flag = 0; return;
            }
            if(x[deep] <= root->val) {
                flag = 0;return;
            }
            x[deep] = root->val; 
        }
        //printf("%d %d %d\n",root->val, deep, flag);
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        flag = 1;
        for(int i = 0; i <= 100000; i ++) 
            if(i%2)
                x[i] = 10000000;
            else x[i] = 0;
        dfs(root, 0);
        //printf("    %d",flag);
        return flag;
    }
};