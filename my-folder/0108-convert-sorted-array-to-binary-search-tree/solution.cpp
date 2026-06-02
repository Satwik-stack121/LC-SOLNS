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
    TreeNode* function(vector<int>& nums, int start, int end){
        if(end<start){
            return nullptr;
        }
        int mid = (start+end+1)/2;

        TreeNode* newRoot = new TreeNode();

        
        newRoot->val=nums[mid];
        newRoot->left=function(nums, start ,mid-1);
        newRoot->right=function(nums, mid+1 ,end);
        return newRoot;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return function(nums, 0 , nums.size()-1);

    }
};
