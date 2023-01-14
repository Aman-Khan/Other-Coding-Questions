    bool checkMerge(vector<int> &range, vector<int> &intervals){
        if(intervals[0]<=range[1]){
            return true;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> range = {intervals[0][0], intervals[0][1]};
        for(int i=0; i<intervals.size(); i++){
            if(checkMerge(range, intervals[i])){
                range[1]=max(range[1], intervals[i][1]);
            }
            else{
                ans.push_back(range);
                range = intervals[i];
            } 
        }
        ans.push_back(range);
        return ans;
    }
