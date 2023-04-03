    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, set<int>> mp;
        for(auto stone:stones) mp[stone]={};
        mp[0].insert(0);

        for(auto steps: mp){
            int pos = steps.first;
            for(auto step: steps.second){
                if(mp.find(pos+step+1)!=mp.end()){
                    mp[pos+step+1].insert(step+1);
                }
                if(pos+step!=pos && mp.find(pos+step)!=mp.end()){
                    mp[pos+step].insert(step);
                }
                if(pos+step-1>pos && mp.find(pos+step-1)!=mp.end()){
                    mp[pos+step-1].insert(step-1);
                }
            }
        }
        return (mp[stones[n-1]].size()!=0)?1:0;
    }
