    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited){
        visited[x][y]=1;

        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nrow = drow[i]+x;
            int ncol = dcol[i]+y;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
                dfs(nrow, ncol, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n<=1) return;
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for(int i=0; i<m-1; i++){ //top
            if(board[0][i]=='O' && !visited[0][i]){
                dfs(0, i, board, visited);
            }
        }

        for(int i=0; i<n-1; i++){ //right
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                dfs(i, m-1, board, visited);
            }
        }
        
        for(int i=m-1; i>0; i--){ //bottom
            if(board[n-1][i]=='O'){
                dfs(n-1, i, board, visited);
            }
        }

        for(int i=n-1; i>0; i--){ //left
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i, 0, board, visited);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
