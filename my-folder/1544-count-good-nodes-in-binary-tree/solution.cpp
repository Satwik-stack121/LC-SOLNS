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
    int DFS(TreeNode* Node , int max){
        if(Node == nullptr){
            return 0;
        }
        int goodcount=0;
        if(max <= Node-> val){
            goodcount++;
            max =Node -> val;
        }

        return goodcount + DFS(Node -> left , max) + DFS( Node -> right , max);
    }
    int goodNodes(TreeNode* root) {
        return DFS(root , INT_MIN);
    }
};
