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
    TreeNode* prevNode = NULL;
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        if(!isValidBST(root->left)){
            return false;
        }

        if(prevNode != NULL && root->val <= prevNode->val){
            return false;
        }

        prevNode = root;

        return isValidBST(root -> right);
    }
};
