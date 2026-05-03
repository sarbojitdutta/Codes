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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        stack<TreeNode*> path; 
        stack<int> sumPath;

        path.push(root);
        sumPath.push(root->val);

        while(!path.empty()){
            TreeNode* temp = path.top();
            path.pop();
            int tempVal = sumPath.top();
            sumPath.pop();

            if(temp -> left == NULL && temp -> right == NULL && tempVal == targetSum){
                return true;
            }

            if(temp->left != NULL){
                path.push(temp->left);
                sumPath.push(temp->left->val + tempVal);
            }
            if(temp->right != NULL){
                path.push(temp->right);
                sumPath.push(temp->right->val + tempVal);
            }


        }
        return false;
    }
};