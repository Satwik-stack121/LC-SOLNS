class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() -1;
        int maxArea = INT_MIN;

        while(l < r) {
            maxArea = std::max(maxArea, std::min(h[l], h[r])* (r - l)) ;
            if(h[r] > h[l]) 
                l++;
            else r--;
        }
        return maxArea;
    }
};
