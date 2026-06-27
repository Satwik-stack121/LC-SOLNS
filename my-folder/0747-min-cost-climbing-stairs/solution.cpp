class Solution {
public:
    int memoized_climb(int step, vector<int>& mem , vector<int>& cost){
        if(step >= cost.size()){
            return 0;
        }
        else if(mem[step] != -1){
            return mem[step];
        }
        else{
            mem[step] = cost[step] + min(memoized_climb(step + 1 , mem , cost) , memoized_climb(step+2 , mem , cost));
            return mem[step]; 
        }
        
    }
    int minCostClimbingStairs(vector<int>& cost){
        vector<int> mem (cost.size()+1 , -1);
        return min(memoized_climb(0 , mem , cost) , memoized_climb(1 , mem , cost));
    }
};
