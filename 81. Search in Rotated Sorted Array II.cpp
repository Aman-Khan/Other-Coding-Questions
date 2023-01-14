    int getPivot(vector<int> &nums){
        int s=0;
        int e=nums.size()-1;
        int pivot=nums[0];
        int mid = s+(e-s)/2;

        while(s<e){
            if(nums[mid]==nums[e]) e--; // to handel [1,1,1,1,0,1,1]
            else if(nums[mid]>=pivot){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return e;
    }

    bool binarySearch(vector<int>& nums, int target, int s, int e){
        int mid = s+(e-s)/2;

        while(s<=e){
            if(nums[mid]==target) return true;
            if(nums[mid]>target) e = mid-1;
            else s = mid+1;
            mid = s+(e-s)/2;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        
        int breakPoint = getPivot(nums);
        if(target>=nums[0]){
            return binarySearch(nums, target, 0, breakPoint);
        }
        else{
            return binarySearch(nums, target, breakPoint, nums.size()-1);
        }
    }
