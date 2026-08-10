class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int g = gas.size();
        for(int i = 0; i <g ;i++){
            int temp = gas[i]-cost[i];
            diff.push_back(temp);
        }
        int starter = 0;
        int total = 0;
        int sum=0;

        for(int i =0 ; i<g ; i++){
            sum+=diff[i];
            total+=diff[i];
            if(total < 0){
                total = 0;
                starter =i+1;
            }
            // else{
            //     starter = i;
            //     total += diff[i];
            // }
                
        }
        if(sum <0){
            return -1;
        }
        return starter;
    }
};
