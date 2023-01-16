    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<int>>& image, int curCol, int n, int m){
        visited[x][y]=1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = drow[i]+x;
            int ncol = dcol[i]+y;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==curCol && visited[nrow][ncol]==0){
                // cout<<nrow<<ncol<<endl;                
                dfs(nrow, ncol, visited, image, curCol, n, m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int curCol=image[sr][sc];
        vector<vector<int>> filled(n, vector<int>(m, 0));
        dfs(sr, sc, filled, image, curCol, n, m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(filled[i][j]==1){
                    filled[i][j]=color;
                }
                else{
                    filled[i][j]=image[i][j];
                }
            }
        }

        return filled;
    }
