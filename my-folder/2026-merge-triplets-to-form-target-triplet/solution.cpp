class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> curr = {0, 0, 0};
        int x = target[0];
        int y = target[1];
        int z = target[2];
        for(const vector<int> &i : triplets){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            if(a <= x && b <= y && c <=z){
                curr[0] = max(a , curr[0]);
                curr[1] = max(b , curr[1]);
                curr[2] = max(c , curr[2]);
            }

            if(curr== target){
                return true;
            }
        }
        return false;
    }
};

