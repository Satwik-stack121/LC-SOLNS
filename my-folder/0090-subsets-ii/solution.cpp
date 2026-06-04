class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& solution, int index){

        solution.push_back(current);

        for(int i=index; i<nums.size(); i++){
            if(i > 0 && i>index && nums[i]==nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums, current, solution, i+1);
            current.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        backtrack(nums, current, solution, 0);
        return solution;
    }
};
