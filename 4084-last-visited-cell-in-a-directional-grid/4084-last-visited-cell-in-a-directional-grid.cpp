class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i=0,j=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[i][j]=true;
        while(true){
            int ni=i,nj=j;
            if(grid[i][j]=='R'){
                nj++;
            }
            if(grid[i][j]=='L'){
                nj--;
                // arr{i,j};
            }
            if(grid[i][j]=='D'){
                ni++;
                // arr{i,j};
            }
            if(grid[i][j]=='U'){
                ni--;
                // arr{i,j};
            }
            if(ni<0||ni>=m||nj<0||nj>=n) break;
            if(visited[ni][nj]) break;
            i=ni;
            j=nj;
            visited[i][j]=true;
        }
        return {i,j};
    }
};