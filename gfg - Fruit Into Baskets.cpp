//https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/

    int totalFruits(int N, vector<int> &fruits) {
        int maxSize=0;
        int cnt=0;
        int ft1;
        int ft2;
        int size=0;
        for(int i=0; i<N; i++){
            if(cnt==0){
                ft1=fruits[i];
                cnt++;
            }
            else if(cnt==1){
                ft2=fruits[i];
                cnt++;
            }
            if(fruits[i]==ft1){
                size++;
            }
            else if(fruits[i]==ft2){
                size++;
            }
            else{
                ft1=fruits[i-1];
                ft2=fruits[i];
                int prev=0;
                int j=i-1;
                while(j>=0 && fruits[j]==ft1){
                    j--;
                    prev++;
                }
                size=prev+1;
            }
            maxSize=max(maxSize, size);
        }
        return maxSize;
    }
