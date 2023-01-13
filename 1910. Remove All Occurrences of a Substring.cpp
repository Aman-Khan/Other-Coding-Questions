    string removeOccurrences(string s, string part) {
        string st="";
        int i=0;
        int n=s.size();
        int l=part.size();

        while(i<n){
            st.push_back(s[i]);
            while(st.size()>=l && st.substr(st.size()-l, st.size())==part){
                st.erase(st.size()-l,st.size());
            }
            i++;
        }
        return st;
    }
