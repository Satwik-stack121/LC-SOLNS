class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> rottencoords;
        int fresho=0;

        for(int r=0 ; r <rows ; r++){
            for(int c =0 ; c<cols ; c++){
                if(grid[r][c] == 2){
                    rottencoords.push({r,c});
                }
                else if(grid[r][c] == 1){
                    fresho++;
                }
            }
        }

        int time=0;
        while(!rottencoords.empty() && fresho > 0){
            int size = rottencoords.size();
            for(int i=0; i<size; i++){
                int r = rottencoords.front().first;
                int c = rottencoords.front().second;
                rottencoords.pop();

                if(r+1<rows && grid[r + 1][c]==1){
                    grid[r+1][c]=2;
                    fresho--;
                    rottencoords.push({r + 1, c});
                }

                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]= 2;
                    fresho--;
                    rottencoords.push({r-1, c});
                }

                if(c+1< cols && grid[r][c+1] ==1){
                    grid[r][c+1] = 2;
                    fresho--;
                    rottencoords.push({r, c+1});
                }

                if(c-1 >= 0 && grid[r][c- 1]== 1) {
                    grid[r][c-1] = 2;
                    fresho--;
                    rottencoords.push({r, c-1});
                }
            }
            time++;
        }
        if(fresho ==0){
            return time;
        }
        return -1;
        
    }
};
