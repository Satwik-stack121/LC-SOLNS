class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> soln;
        int n = intervals.size();
        int i=1;
        if (n == 0){
            return soln;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> newinterval = intervals[0];
        while(i < n){

            if(intervals[i][0] <= newinterval[1]){
                
                newinterval[0] = (min(intervals[i][0] , newinterval[0]));
                newinterval[1] = (max(intervals[i][1] , newinterval[1]));

            }
            else {
                soln.push_back(newinterval);
                newinterval = intervals[i];

            }
            i++;
        }
        soln.push_back(newinterval);

        return(soln);
    }
};

