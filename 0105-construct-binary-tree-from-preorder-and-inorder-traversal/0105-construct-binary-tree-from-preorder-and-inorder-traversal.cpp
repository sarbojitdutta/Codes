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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexMap;

        for(int i = 0; i < inorder.size(); i++){
            indexMap[inorder[i]] = i;
        }
        return splitTree(preorder, indexMap, 0, 0, inorder.size() - 1);
    }

    TreeNode* splitTree(vector<int>& preorder,
                        unordered_map<int, int>& indexMap, int rootIndex, int left,
                        int right)
    {
        TreeNode* root = new TreeNode(preorder[rootIndex]);

        int mid = indexMap[preorder[rootIndex]];

        if(mid > left){
            root->left = splitTree(preorder, indexMap, rootIndex+1, left, mid-1);
        }
        if(mid < right){
            root->right = splitTree(preorder, indexMap, rootIndex + mid-left + 1, mid+1, right);
        }
        return root;
    }
};