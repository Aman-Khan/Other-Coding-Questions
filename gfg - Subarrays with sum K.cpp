    int findSubArraySum(int Arr[], int N, int k)
    {
        if(N==0) return 0;
        int cnt = 0;
        map<int, int> prefix;
        int sum = 0;
        for(int i=0; i<N; i++){
            sum+=Arr[i];
            if(sum==k) cnt++;
            if(prefix.find(sum-k)!=prefix.end()){
                cnt+=prefix[sum-k];   
            }
            prefix[sum]+=1;
        }
        return cnt;
    }
