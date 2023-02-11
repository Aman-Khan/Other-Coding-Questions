    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int i=0;
        int j=sz-1;
        while(i<j){
            while(i<sz && nums[i]!=val) i++;
            while(j>=0 && nums[j]==val) j--;
            if(i<j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        i=0;
        while(i<sz && nums[i]!=val) i++;
        return i;
    }
