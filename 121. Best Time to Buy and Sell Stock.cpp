    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int i=prices.size()-1;
        int maxi = 0;
        while(i>=0){
            if(!st.empty() && st.top()>prices[i]){
                maxi = max(maxi, st.top()-prices[i]);
            }
            else{
                st.push(prices[i]);
            }
            i--;
        }
        return maxi;
    }
