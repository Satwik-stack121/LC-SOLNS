class Solution {
public:
    int rows=0;
    int cols=0;
    void dfs(int r, int c, vector<vector<int>>& heights , vector<vector<bool>>& map){
        map[r][c] = true;
        if(r>0 && !map[r-1][c] && heights[r-1][c]>=heights[r][c]){
            dfs(r-1 , c, heights , map);
        }
        if(r+1<rows && !map[r+1][c] && heights[r+1][c]>=heights[r][c]){
            dfs(r+1 , c, heights , map);
        }
        if(c>0 && !map[r][c-1] && heights[r][c-1]>=heights[r][c]){
            dfs(r , c-1, heights , map);
        }
        if(c+1<cols && !map[r][c+1] && heights[r][c+1]>=heights[r][c]){
            dfs(r , c+1 , heights , map);
        }
    }
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<bool>> p(rows , vector<bool>(cols , false));
        vector<vector<bool>> a(rows , vector<bool>(cols , false));
        vector<vector<int>> ans;
        for(int r = 0 ; r<rows ; r++){
            if(!p[r][0]){
                dfs(r , 0 , heights , p);
            }
        }
        for(int r = 0 ; r<rows ; r++){
            if(!a[r][cols-1]){
                dfs(r , cols-1 , heights , a);
            }
        }
        for(int c = 0 ; c<cols ; c++){
            if(!p[0][c]){
                dfs(0 , c , heights , p);
            }
        }
        for(int c = 0 ; c<cols ; c++){
            if(!a[rows-1][c]){
                dfs(rows-1 , c , heights , a);
            }
        }

        for(int r=0; r<rows; r++){
            for(int c=0; c <cols; c++){
                if(p[r][c] && a[r][c]){
                    ans.push_back({r, c});
                }
            }
        }
        return ans;
    }
};
