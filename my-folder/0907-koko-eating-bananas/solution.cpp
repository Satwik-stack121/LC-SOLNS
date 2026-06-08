class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int min_speed=1;
        // int max_speed=INT_MAX;
        // int min_time=0;
        int left=1;
        int right=INT_MAX;

        while(left<right){
            int mid = left+(right-left)/2;

            int curr_h=0;
            for(const int& i: piles){
                curr_h+= (i+ mid -1) /mid;
            }
            if(curr_h <= h){
                right=mid;
            }

            else{
                left=mid+1;
            }
        }   
        return left;
    }
};
