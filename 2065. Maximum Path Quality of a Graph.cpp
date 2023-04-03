    void createAdj(vector<vector<int>>& edges, vector<pair<int, int>> adj[]){
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
    }

    void trav(int node, vector<pair<int, int>> adj[], vector<int>& values, int col, int& maxCol, int maxTime){
        if(maxTime<0) return;
        else if(node == 0){
            maxCol = max(maxCol, col);
        }

        for(auto i:adj[node]){
            int val = values[i.first];
            values[i.first]=0;
            trav(i.first, adj, values, col+val, maxCol, maxTime-i.second);
            values[i.first]=val;
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int, int>> adj[n];
        createAdj(edges, adj);
        int maxCol = values[0];
        
        trav(0, adj, values, 0, maxCol, maxTime);
        return maxCol;
    }
