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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastvisited = NULL;

        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr -> left;
            }
            TreeNode* node = st.top();

            if(node->right != NULL && lastvisited != node->right){
                curr = node->right;
            }
            else{
                postorder.push_back(node->val);
                lastvisited = node;
                st.pop();
            }
        }
        return postorder;
    }
};