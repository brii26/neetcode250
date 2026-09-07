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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> q;
        vector<vector<int>> res;
        // initial push

        // while loop
        // check vector if all nullptr return
        // else push numbernya to res vector<int> to -> vector<vector<int>>
        // for all child within nodes inside vector push anaknya
        // while not empty pop push kevector yang di pake buat next iteration

        q.push_back(root);
        while (true) {

            // take all non-nullptr values within vectors
            vector<int> el;
            vector<TreeNode*> childs;
            for(TreeNode* node : q ) {
                if(node) {
                    el.push_back(node->val);
                    childs.push_back(node->left);
                    childs.push_back(node->right);
                }
            }

            // if nodes are all nullptr early break loop, else push vector int
            if (el.empty()) {
                break;
            } else {
                res.push_back(el);
            }

            // pindain value
            q.clear();
            for (TreeNode* node : childs) {
                q.push_back(node);
            }
        }
        return res;
    }
};
