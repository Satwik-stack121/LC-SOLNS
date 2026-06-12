class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> unique;

        for(const int& num : nums){
            if(unique.count(num)){
                return num;
            }
            else{
                unique.insert(num);
            }
        }
        return -1;
    }
};
