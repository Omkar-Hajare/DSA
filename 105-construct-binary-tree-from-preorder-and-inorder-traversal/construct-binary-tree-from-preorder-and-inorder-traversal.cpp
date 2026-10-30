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
    unordered_map<int, int> inorderIndex;

    TreeNode* build(
        vector<int>& preorder,
        int inStart,
        int inEnd
    ) {
        if (inStart > inEnd) {
            return nullptr;
        }
 
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex =
            inorderIndex[rootValue];
 
        root->left = build(
            preorder,
            inStart,
            rootIndex - 1
        );
 
        root->right = build(
            preorder,
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
        inorderIndex.clear();
         for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
 
        return build(
            preorder,
            0,
            inorder.size() - 1
        );
    }
};