class Solution {
public:
    int memoized_climb(int n , vector<int>& mem){
        if(n ==0){
            return 1;
        }
        else if(n == 1){
            return 1;
        }
        else if(mem[n] != -1){
            return mem[n];
        }
        else{
            mem[n] = memoized_climb(n-1 , mem) + memoized_climb(n-2 , mem);
            return mem[n];
        }
    }
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);
        return memoized_climb(n , mem);
    }
};
