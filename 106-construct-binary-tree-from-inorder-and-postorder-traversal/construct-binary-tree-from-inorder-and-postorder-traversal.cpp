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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indexMap;

        for(int i = 0; i < inorder.size(); i++){
            indexMap[inorder[i]] = i;
        }
        return splitTree(postorder,indexMap, postorder.size() - 1, 0,  inorder.size()-1);
    }

    TreeNode* splitTree(vector<int>& postorder,unordered_map<int, int>& indexMap,int rootIndex, int left, int right){
        TreeNode* root = new TreeNode(postorder[rootIndex]);

        int mid = indexMap[postorder[rootIndex]];

        if(mid<right){
            root->right = splitTree(postorder, indexMap, rootIndex - 1, mid + 1, right);
        }

        if(mid>left){
            root->left = splitTree(postorder, indexMap, rootIndex - (right - mid) - 1, left, mid - 1);
        }
        return root;
    }
};