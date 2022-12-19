    int binarySearchIn2D(vector<vector<int>> nums,int row, int target){
        int i=0;
        int j=nums[0].size()-1;
        int mid = i+(j-i)/2;
        while(i<=j){
            if(nums[row][mid]==target) return mid;
            else if(nums[row][mid]<target) i=mid+1;
            else j=mid-1;
            mid = i+(j-i)/2;
        }
        return -1;
    }

    int lowerbound(vector<vector<int>> nums, int target){
        int col = nums[0].size()-1;
        int ind =-1;
        int i=0;
        int j=nums.size()-1;
        int mid = i+(j-i)/2;
        while(i<=j){
            if(nums[mid][col]>=target){
                ind = mid;
                j=mid-1;
            }
            else i=mid+1;
            mid = i+(j-i)/2;
        }
        return ind;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=lowerbound(matrix, target);
        if(col==-1) return false;
        if(binarySearchIn2D(matrix, col, target)==-1) return false;
        return true;
    }
