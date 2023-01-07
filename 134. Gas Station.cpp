//1st Approach
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        int n = gas.size();
        int start = 0;
        for(int i=0; i<n; i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }
        }
        if(balance+deficit>=0) return start;
        return -1; 
    }


//2nd Approach
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {    
        int start=-1;
        int gasInTank=0;
        int n=gas.size();
        int i=0;
        int maxDis=0;
        int trav=0;
        int cnt=0;
        while(true){
            if(cnt==n) return -1;
            if(maxDis==n) break;
            if(gasInTank==0){
                start = i%n;
            }
            gasInTank+=gas[i%n];
            if(cost[i%n]>gasInTank){
                gasInTank = 0;
                trav=0;
                cnt++;
            }
            else{
                gasInTank-=cost[i%n];
                trav++;
                maxDis=max(maxDis, trav);
            }
            i++;
        }
        cout<<"travel : "<<maxDis<<endl;
        return start;
    }
