string convert(string s){
        string ans = "";
        for(int i=0; i<s.length(); ){
            char ch = s[i];
            int cnt = 0;
            while(i<s.length() && s[i]==ch){
                i++;
                cnt++;
            }
            ans+=to_string(cnt)+ch;
        }
        return ans;
    }

    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "11";
        for(int i=1; i<n-1; i++){
            ans = convert(ans);
        }
        return ans;
    }
