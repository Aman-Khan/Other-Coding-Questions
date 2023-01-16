    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& grid, int n, int m){
        visited[x][y]=1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = drow[i]+x;
            int ncol = dcol[i]+y;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs(nrow, ncol, visited, grid, n, m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for(int i=0; i<m-1; i++){
            if(grid[0][i] && !visited[0][i]){
                dfs(0, i, visited, grid, n, m);
            }
        }
        for(int i=0; i<n-1; i++){
            if(grid[i][m-1] && !visited[i][m-1]){
                dfs(i, m-1, visited, grid, n, m);
            }
        }
        for(int i=m-1; i>0; i--){
            if(grid[n-1][i] && !visited[n-1][i]){
                dfs(n-1, i, visited, grid, n, m);
            }
        }
        for(int i=n-1; i>0; i--){
            if(grid[i][0] && !visited[i][0]){
                dfs(i, 0, visited, grid, n, m);
            }
        }
        int enclaves=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
