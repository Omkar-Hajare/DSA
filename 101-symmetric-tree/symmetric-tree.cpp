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
    bool isSymmetric(TreeNode* root) {
       if (root == nullptr) {
            return true;
        }
 
        stack<pair<TreeNode*, TreeNode*>> nodesStack;
        nodesStack.push({root->left, root->right});
 
        while (!nodesStack.empty()) {
            auto [leftNode, rightNode] = nodesStack.top();
            nodesStack.pop();
 
            if (leftNode == nullptr && rightNode == nullptr) {
                continue;
            }
 

            if (leftNode == nullptr || rightNode == nullptr) {
                return false;
            }
 
            if (leftNode->val != rightNode->val) {
                return false;
            }
 

            nodesStack.push({
                leftNode->right,
                rightNode->left
            });
 
            nodesStack.push({
                leftNode->left,
                rightNode->right
            });
        }
 
        return true; 
    }
};