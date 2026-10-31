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
private:
    int preIndex;

    TreeNode* build(
        vector<int>& preorder,
        vector<int>& inorder,
        int inStart,
        int inEnd
    ) {
        if (inStart > inEnd) {
            return nullptr;
        }
 

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);
 
        int rootIndex = inStart;

        while (
            rootIndex <= inEnd &&
            inorder[rootIndex] != rootValue
        ) {
            rootIndex++;
        }
 
        root->left = build(
            preorder,
            inorder,
            inStart,
            rootIndex - 1
        );
 
        root->right = build(
            preorder,
            inorder,
            rootIndex + 1,
            inEnd
        );
 
        return root;
    }
 
public:
    TreeNode* buildTree(
        vector<int>& preorder,
        vector<int>& inorder
    ) {
        preIndex = 0;
 
        return build(
            preorder,
            inorder,
            0,
            inorder.size() - 1
        );
    }
};