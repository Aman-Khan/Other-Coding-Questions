vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strsTemp = strs;
        map<string, vector<int>> xMap;
        for(int i=0; i<strsTemp.size(); i++){
            sort(strsTemp[i].begin(), strsTemp[i].end());
            if(xMap.find(strsTemp[i])!=xMap.end()){
                xMap[strsTemp[i]].push_back(i);
            }
            else{
                xMap[strsTemp[i]].push_back(i);
            }
        }        
        vector<vector<string>> ans;

        for(auto i:xMap){
            vector<string> temp;
            for(auto j:i.second){
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
