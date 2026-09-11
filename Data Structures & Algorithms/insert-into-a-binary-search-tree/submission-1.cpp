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
    void dfs(TreeNode* curr, int val) {
        // theres some conditions here
        // bigger put right,
        // smaller put left
        TreeNode* new_node = new TreeNode(val);
        while (true) {
            if (curr->val < val) {
                if(!curr->right) {
                    curr->right = new_node;
                    break;
                }
                curr = curr->right;
            } else {
                if(!curr->left) {
                    curr->left = new_node;
                    break;
                }
                curr = curr->left;
            }

        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        dfs(root, val);
        return root;
    }
};