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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
 
        stack<pair<TreeNode*, bool>> nodesStack;
        nodesStack.push({root, false});
 
        unordered_map<TreeNode*, int> heightMap;
 
        while (!nodesStack.empty()) {
            auto [node, visited] = nodesStack.top();
            nodesStack.pop();
 
            if (!visited) {
                nodesStack.push({node, true});
 
                if (node->right != nullptr) {
                    nodesStack.push({node->right, false});
                }
 
                if (node->left != nullptr) {
                    nodesStack.push({node->left, false});
                }
            } else {
                
                int leftHeight = node->left
                    ? heightMap[node->left]
                    : 0;
 
                int rightHeight = node->right
                    ? heightMap[node->right]
                    : 0;
 
                if (abs(leftHeight - rightHeight) > 1) {
                    return false;
                }
 
                heightMap[node] =
                    1 + max(leftHeight, rightHeight);
            }
        }
 
        return true;
        
    }
};