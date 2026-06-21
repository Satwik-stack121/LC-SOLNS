class Solution {
public:
    int area = 0;
    int currarea=0;
    void dfs(vector<vector<int>>& grid , int r , int c ){
        const int rows=grid.size();
        const int cols=grid[0].size();
        if(r>=rows || r<0 || c>=cols || c<0 || grid[r][c]==0){
            return;
        }
        currarea++;
        grid[r][c] = 0;
        dfs(grid , r+1 , c );
        dfs(grid , r-1 , c );
        dfs(grid , r , c+1 );
        dfs(grid , r , c-1 );
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int r=0 ; r<grid.size() ; r++){
            for(int c= 0 ; c < grid[0].size() ; c++){
                if(grid[r][c]==1){
                    currarea=0;

                    dfs(grid , r ,c);
                    if(currarea>area){
                        area=currarea;
                    }

                }
            }
        }
        return area;
    }
};
