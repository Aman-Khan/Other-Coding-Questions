    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>> &visited, vector<pair<int, int>> &temp, int n, int m, int ox, int oy){
        visited[x][y]=1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int nrow = drow[i]+x;
            int ncol = dcol[i]+y;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                temp.push_back({nrow-ox, ncol-oy});
                dfs(nrow, ncol, grid, visited, temp, n, m, ox, oy);
            }
        }
    
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> ans;
        vector<pair<int, int>> temp;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && !visited[i][j]){
                    temp.push_back({i-i, j-j});
                    dfs(i, j, grid, visited, temp, n, m, i, j);
                    ans.insert(temp);
                    temp.clear();
                }
            }
        }
        return ans.size();
    }
