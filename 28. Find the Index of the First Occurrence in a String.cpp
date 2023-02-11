    int strStr(string haystack, string needle) {
        int len = needle.length();
        int hlen = haystack.length();
        if(hlen<len) return -1;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[0]){
                int ind=i;
                int cnt=0;
                int j=0;
                while(i<hlen && j<len && haystack[i]==needle[j]){
                    i++;
                    j++;
                    cnt++;
                } 
                if(cnt==len){
                    return ind;
                }
                else i=ind;
            }
        }
        return -1;
    }
